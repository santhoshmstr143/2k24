const results = document.querySelector('#results');
const resultsprompt=document.querySelector('#result-prompt');
const ma=document.getElementsByTagName('main')[0];
const btn=document.getElementById('search-btn');
const yourSelect = document.getElementById("explicit");
const timeSelect= document.getElementById("max-time");
const btn2=document.getElementById('clear-filters');

btn2.addEventListener('click',() =>
{
    timeSelect.value='5';
    yourSelect.value='explicit';
});

btn.addEventListener('click', async (event) => {
    // Prevent the default form submission behavior
    event.preventDefault();
    resultsprompt.innerHTML = 'Loading...';
    results.innerHTML = '';
    try {
        ma.removeChild(document.getElementById('icon'));
    } catch (NetworkError) {
        
    }
    
    // Get the search term entered by the user
    const term = document.querySelector('#search-input').value;
    const ex=yourSelect.selectedOptions[0].value;
    const mi=timeSelect.value;
    console.log(term);
    console.log(ex);
    console.log(mi);
    try
    {
    // Make an asynchronous request to the iTunes API with the search term
    const response = await fetch(`https://itunes.apple.com/search?term=${term}&entity=song&limit=200`);
    
    // Parse the JSON response
    const data = await response.json();
    console.log(data);
    // Clear the results div
    
    results.classList.add('name_div');

    // If the search returned no results, display a message in the results div and exit the function
    if (data.results.length === 0) {
        resultsprompt.innerHTML = 'Aww... Snap, No Result...';
        results.innerHTML='';
        return;
    }
    var count=0;
    resultsprompt.innerHTML='<p>RESULTS</p><a href="#results" style="align-self:center;color:aliceblue;">  &#x2193</a>'
    // Iterate through the search results and display each one in the results div
    for (let i = 0; i < data.results.length; i++) {
        if(ex === 'cleaned' && data.results[i].collectionExplicitness === 'explicit')
        {
            continue;
        }
        if( data.results[i].trackTimeMillis > 60000*mi)
        {
            continue;
        }
        if(count === 10)
        {
            break;
        }
        count++;
        const result = data.results[i];
        const trackName = result.trackName;
        const artistName = result.artistName;
        const artworkUrl = result.artworkUrl100;
        const previewUrl = result.previewUrl;

        // Create a new div to display the result
        const resultDiv = document.createElement('div');
        resultDiv.classList.add('song_div');

        // Create a div to display the song and artist name
        const infoDiv = document.createElement('div');
        infoDiv.classList.add('song_table');

        // Create an image element to display the artwork
        const img = document.createElement('img');
        img.classList.add('song_img');
        img.src = artworkUrl;
        infoDiv.appendChild(img);

         // Create an audio element to play the audio snippet
         const audio = document.createElement('audio');
         audio.src = previewUrl;
         audio.controls = true;
         audio.class=audio-1;
         infoDiv.appendChild(audio);
 

        const trackNameP = document.createElement('p');
        trackNameP.classList.add('song_name');
        trackNameP.innerHTML = trackName;
        infoDiv.appendChild(trackNameP);

        const artistNameP = document.createElement('p');
        artistNameP.classList.add('song_artist')
        artistNameP.innerHTML = artistName;
        infoDiv.appendChild(artistNameP);
        resultDiv.appendChild(infoDiv);
        // Add the result div to the results div on the HTML page
        results.appendChild(resultDiv);
    }
    if (count === 0) {
        resultsprompt.innerHTML = 'Aww... Snap, No Result...';
        results.innerHTML='';
        return;
    }
    //ma.innerHTML+='<a href="#head-name" id="icon">&#x2191</a>';
    ma.insertAdjacentHTML('beforeend','<a href="#head-name" id="icon">&#x2191</a>');
} catch (NetworkError) {
    resultsprompt.innerHTML = 'Network Not Found. Please Try Again.';
}
});
