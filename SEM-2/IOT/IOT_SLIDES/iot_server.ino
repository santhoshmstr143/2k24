#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#define PASSWORD "xxxxxxx"

//#include "pass.h"
// Replace with your WiFi credentials
const char* ssid = "Your_SSID";
const char* password = PASSWORD;

// Create WebServer instance on port 80
WebServer server(80);

// Function to generate random sensor values
float getRandomTemperature() {
    return random(200, 350) / 10.0;  // 20.0°C to 35.0°C
}

float getRandomHumidity() {
    return random(400, 700) / 10.0;  // 40.0% to 70.0%
}

// Handler function for GET /sensor
void handleSensorData() {
    DynamicJsonDocument doc(200);
    doc["temperature"] = getRandomTemperature();
    doc["humidity"] = getRandomHumidity();

    String jsonResponse;
    serializeJson(doc, jsonResponse);
    
    server.send(200, "application/json", jsonResponse);
}

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());

    // Define REST API endpoint
    server.on("/sensor", HTTP_GET, handleSensorData);

    // Start the server
    server.begin();
    Serial.println("Server started.");
}

void loop() {
    server.handleClient();
}
