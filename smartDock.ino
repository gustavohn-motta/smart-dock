/*
  Author: Gustavo Motta
  sketch: pwm I2C
  data:   13/09/2025
*/

//add libs
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP8266WiFi.h>
#define ESPALEXA_DEBUG
#include <Espalexa.h>



// wifi conect
boolean connectWifi();

// Change this!!
const char* ssid = "...";
const char* password = "...";

boolean wifiConnected = false;

//instance espalexa 
Espalexa espalexa;

//instance objects
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//declare functions
void writeServos(int position, int time);
void beginServos();

void servo1(uint8_t brightness);
void servo2(uint8_t brightness);
void servo3(uint8_t brightness);
void servo4(uint8_t brightness);

void setup() {

  Serial.begin(115200);

  // Initialise wifi connection
  wifiConnected = connectWifi();
  if(wifiConnected){
    espalexa.addDevice("servo 1", servo1);
    espalexa.addDevice("servo 2", servo2);
    espalexa.addDevice("servo 3", servo3);
    espalexa.addDevice("servo 4", servo4);
    beginServos();
    espalexa.begin();
  }else {
    while (1) {
      Serial.println("Cannot connect to WiFi. Please check data and reset the ESP.");
      delay(2500);
    }
  }
}

void loop() {
   espalexa.loop();
   delay(1);

}

//servo functions
void servo1(uint8_t brightness){moveServo(0, brightness);}
void servo2(uint8_t brightness){moveServo(1, brightness);}
void servo3(uint8_t brightness){moveServo(2, brightness);}
void servo4(uint8_t brightness){moveServo(3, brightness);}

void moveServo(int servoNumber,uint8_t state){
  if(state){
    Serial.print("ON, state: ");
    Serial.println(state);
    writeServos(servoNumber, 100);
  } else {
    Serial.print("OFF, brightness: ");
    Serial.println(state);
    writeServos(servoNumber, 0);
  }
}

//functions
void writeServos(int nServo, int position){
  #define SERVOMIN 205
  #define SERVOMAX 409

  int pos = map(position, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo, 0, pos);
}

void beginServos() {
  #define Frequency 50 // ref value of servo

  pwm.begin(); // init pwm object
  pwm.setPWMFreq(Frequency); // Define work frequency servo
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20){
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state){
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}
