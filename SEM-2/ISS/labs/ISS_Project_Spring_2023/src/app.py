from fastapi import FastAPI, Request, Form, Depends, Response
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates
from fastapi.staticfiles import StaticFiles
import sqlite3

class DBclass:
    def __init__(self, path):
        self.path = path

    def connect(self):
        return sqlite3.connect(self.path)

    def execute(self, query, params=()):
        with self.connect() as db:
            cur = db.cursor()
            cur.execute(query, params)
            headers = [i[0] for i in cur.description] if cur.description else []
            return headers, cur.fetchall()

    def add(self, query, params):
        with self.connect() as db:
            cur = db.cursor()
            cur.execute(query, params)
            db.commit()
        print(f"Executed Query: {query} with Params: {params}")

    def find(self, query, params=()):
        with self.connect() as db:
            cur = db.cursor()
            cur.execute(query, params)
            return cur.fetchall()

    def remove(self, query, params=()):
        with self.connect() as db:
            cur = db.cursor()
            cur.execute(query, params)
            db.commit()
        print(f"Removed with Query: {query} and Params: {params}")

app = FastAPI()
app.mount("/static", StaticFiles(directory="static"), name="static")
templates = Jinja2Templates(directory="templates")

@app.get("/", response_class=HTMLResponse)
@app.get("/index.html", response_class=HTMLResponse)
def start(request: Request):
    return templates.TemplateResponse("index.html", {"request": request})

@app.get("/home.html", response_class=HTMLResponse)
def home(request: Request):
    return templates.TemplateResponse("home.html", {"request": request})

@app.get("/artists.html", response_class=HTMLResponse)
def artist(request: Request):
    return templates.TemplateResponse("artists.html", {"request": request})

@app.get("/about.html", response_class=HTMLResponse)
def about(request: Request):
    return templates.TemplateResponse("about.html", {"request": request})

@app.get("/search.html", response_class=HTMLResponse)
def search(request: Request):
    return templates.TemplateResponse("search.html", {"request": request})

@app.get("/spotlight.html", response_class=HTMLResponse)
def spotlight(request: Request):
    return templates.TemplateResponse("spotlight.html", {"request": request})

@app.get("/playlist.html", response_class=HTMLResponse)
@app.post("/playlist.html", response_class=HTMLResponse)
def play(request: Request, something: str = Form(default=None)):
    db = DBclass('playlist.db')
    print(something)
    if request.method == 'POST' and something:
        db.remove('DELETE FROM Songs WHERE Name=?', (something,))

    query = 'SELECT * FROM Songs'
    headers, data = db.execute(query)
    print(data)
    return templates.TemplateResponse(
        "playlist.html",
        {"request": request, "navigation": data, "s": len(data)}
    )
    
# Favicon route to handle /favicon.ico explicitly
@app.get("/favicon.ico", include_in_schema=False)
async def favicon():
    try:
        with open("static/favicon.ico", "rb") as f:
            return Response(content=f.read(), media_type="image/x-icon")
    except FileNotFoundError:
        return Response(status_code=204)  # No Content, browser will ignore

@app.get("/{artist}/{album_name}", response_class=HTMLResponse)
@app.post("/{artist}/{album_name}", response_class=HTMLResponse)
def handle_album(
    request: Request,
    artist: str,
    album_name: str,
    something: str = Form(default=None)
):
    db = DBclass('playlist.db')

    if request.method == 'POST' and something:
        try:
            song_name, song_detail = something.split(",", 1)
            elem = db.find('SELECT * FROM Songs WHERE Name=?', (song_name,))
            print(f"Found song: {elem}")
            
            if not elem:
                print(f"Adding new song: {song_name} with time: {song_detail}")
                db.add('INSERT INTO Songs (Name, Time) VALUES (?, ?)', (song_name, song_detail))
        except ValueError:
            print("Invalid format in form submission: expected 'song_name,song_detail'")
            return templates.TemplateResponse(f"{artist}/{album_name}", {"request": request})

    return templates.TemplateResponse(f"{artist}/{album_name}", {"request": request})

@app.get("/{artist}", response_class=HTMLResponse)
def handle_artist(request: Request, artist: str):
    return templates.TemplateResponse(f"{artist}", {"request": request})

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)