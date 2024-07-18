
// Device libraries (Arduino ESP32/ESP8266 Cores)
#include <ESP8266WiFi.h>
#include "CTBot.h"


#define buzzer 17          //pin buzzer
#define relay 18              //pin relay

CTBot myBot;
String ssid = "xxxxx";      //ssid WiFi
String pass = "xxxxx";      //password Wifi
String token = "xxxxx";      //token bot telegram
const int id = xxxxx; //id telegram


void setup()
{
  
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite (buzzer, 1);
  digitalWrite (relay, 1);  
  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  if (myBot.testConnection()) {
    Serial.println("Good Connection");
  } else {
    Serial.println("Bad Connection");
  }

  myBot.sendMessage(id, "Hello, Welcome to Relay Switching");
  Serial.println("Pesan Terkirim");
}


void loop()
{
  TBMessage msg;
  
  if (myBot.getNewMessage(msg, "/buzzer_on")) {
    digitalWrite (buzzer, 0);
    myBot.sendMessage(id, "Buzzer Menyala");
    
  }else if (myBot.getNewMessage(msg, "/buzzer_of")) {
    digitalWrite (buzzer, 1);
    myBot.sendMessage(id, "Buzzer Dimatikan");
    
  }else if (myBot.getNewMessage(msg, "/relay_on")) {
    digitalWrite (relay, 0);
    myBot.sendMessage(id, "Lampu Menyala");
    
  }else if (myBot.getNewMessage(msg, "/relay_off")) {
    digitalWrite (relay, 1);
    myBot.sendMessage(id, "Lampu Dimatikan");
  }

}
