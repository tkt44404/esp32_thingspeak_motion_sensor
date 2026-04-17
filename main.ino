#include <HTTPClient.h>
#include <WiFi.h>
#include "config.h"

#define pirPin 21
#define led 2

unsigned long lastTriggerTime = 0;
const unsigned long cooldown = 15000;


void setup() {
  pinMode(pirPin, INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

  Serial.begin(115200);
  
  WiFi.begin(SSID,PASSWORD)
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}


void sendToThingSpeak(){
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    return;
  }

  HTTPClient http;

   String url = String(SERVER) +
               "?api_key=" + String(API_KEY) +
               "&field1=1";

  Serial.println("Sending to ThingSpeak...");
  Serial.println(url);

  http.begin(url);

  int httpCode = http.GET();

  Serial.print("HTTP Response Code: ");
  Serial.println(httpCode);

  http.end();
}


void isMotionDetected() {

  int motion = digitalRead(pirPin);
  unsigned long currentTime = millis();

  if (motion == HIGH) {

    if (currentTime - lastTriggerTime > cooldown) {

      Serial.println("Motion Detected!");

      digitalWrite(led, HIGH);
      delay(2000);
      digitalWrite(led,LOW);

      lastTriggerTime = currentTime;

      delay(15000);
      
      sendToThingSpeak();

      delay(30000);
    }

  } else {
    digitalWrite(led, LOW);
  }
}


void loop() {
  isMotionDetected();
}