#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* wifiName = "IPHONE 20 PRO";
const char* wifiPass = "mokorutoaitokotoz";
WiFiClient client;

// Web Server address to read/write from
const char* host = "http://triall090909.000webhostapp.com/Monitor%20&%20Controll/parseApi.php";
const int ledPin = 2; // Ganti dengan pin yang sesuai

// Mappings untuk huruf-huruf Morse
const char* morseCodeMapping[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

int currentMessageId = 0;

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.print("Connecting to ");
  Serial.println(wifiName);
  WiFi.begin(wifiName, wifiPass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;  // Declare object of class HTTPClient
  Serial.print("Request Link: ");
  Serial.println(host);
  http.begin(client, host);  // Specify request destination
  String statusResponse;

  int httpCode = http.GET();  // Send the request
  String payload = http.getString();  // Get the response payload from server

  Serial.print("Response Code: ");  // 200 is OK
  Serial.println(httpCode);  // Print HTTP return code

  Serial.print("Returned data from Server: ");
  Serial.println(payload);  // Print request response payload

  if (httpCode == 200) {
    // Allocate JsonBuffer
    // Use arduinojson.org/assistant to compute the capacity.
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
    DynamicJsonDocument jsonBuffer(capacity);

    // Parse JSON object
    DeserializationError error = deserializeJson(jsonBuffer, payload);
    if (error) {
      Serial.print("Parsing failed: ");
      Serial.println(error.c_str());
      return;
    }

    // Decode JSON/Extract values
    const JsonObject& root = jsonBuffer["data"];
    currentMessageId = root["id"];
    const char* sender = root["sender"];
    const char* msg = root["msg"];

    String text = String(sender) + " " + String(msg);
    Serial.println("Received message: " + text);

    translateAndPlayMorse(text);
  } else {
    Serial.println("Error in response");
  }

  http.end();  // Close connection
  delay(1000);  // GET Data every 1 second
}

void translateAndPlayMorse(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = toupper(text.charAt(i));
    if (c == ' ') {
      // Jeda antara kata
      delay(700);
    } else {
      int index = c - 'A';
      if (index >= 0 && index < 26) {
        String morseCode = morseCodeMapping[index];
        playMorseCode(morseCode);
      }
    }

    // Jeda antara karakter
    delay(300);
  }
  
  // Setelah selesai memainkan Morse, panggil fungsi untuk mengupdate flag
  updateFlag(currentMessageId);
}

void playMorseCode(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    char c = morseCode.charAt(i);
    if (c == '.') {
      // Bunyi pendek
      digitalWrite(ledPin, HIGH);
      delay(200); // Durasi bunyi pendek (ms)
      digitalWrite(ledPin, LOW);
    } else if (c == '-') {
      // Bunyi panjang
      digitalWrite(ledPin, HIGH);
      delay(600); // Durasi bunyi panjang (ms)
      digitalWrite(ledPin, LOW);
    }

    // Jeda antara tanda Morse
    delay(200);
  }

  // Jeda antara karakter Morse
  delay(200);
}

void updateFlag(int messageId) {
  String url = "http://triall090909.000webhostapp.com/Monitor%20&%20Controll/updateFlag.php?id=" + String(messageId);
  HTTPClient http;
  http.begin(client, url);

  int httpCode = http.GET();
  if (httpCode == 200) {
    String response = http.getString();
    Serial.println("Response from Server: " + response);
    if (response.indexOf("Flag update successful") != -1) {
      Serial.println("Flag update successful");
    } else {
      Serial.println("Failed to update flag");
    }
  } else {
    Serial.println("Failed to connect to server");
  }

  http.end();
}
