
#include <string.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "sxRsk_QVDT4XZbqTc9lOX-XKlzJAhtDa";
char ssid[] = "R2";
char pass[] = "123456789";
String i = "ok";
int led1;
int temp=5;
String val  = "";

BLYNK_WRITE(V0){ 
  val = param.asStr(); // V0 to a variable
  led1=val[0]-48;
  Serial.println(led1); // Send back to atmega
}

BLYNK_READ(V1){
  temp=(i[0]-48)*10+(i[1]-48);
  Blynk.virtualWrite(V1,temp); // Update temp
  Blynk.virtualWrite(V0,led1); // Update button
}

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
  if(Serial.available()>0){
    i=Serial.readString();
    led1=i[2]-48;
  }
  delay(300);
}
