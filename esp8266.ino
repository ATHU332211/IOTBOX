
 

#include <Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "***************";//Enter your Auth token
char ssid[] = "Atharva";//Enter your WIFI name
char pass[] = "Atharva3102";//Enter your WIFI password

BlynkTimer timer;

void moisture() {
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 100);
  Blynk.virtualWrite(V0, value);
  Serial.println(value);
}

void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
 pinMode(D1, OUTPUT);
 pinMode(D2, OUTPUT);
 pinMode(D3, OUTPUT);

 digitalWrite(D0, HIGH);
 digitalWrite(D1, HIGH);
 digitalWrite(D2, HIGH);
 digitalWrite(D3, HIGH);
  
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, moisture);

}
void loop() {
  Blynk.run();
  timer.run();
}
