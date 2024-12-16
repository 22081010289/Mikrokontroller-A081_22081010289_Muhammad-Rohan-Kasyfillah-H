#include <Arduino.h>

const int baud = 115200;

const int pinT1 = 34;
const int pinT2 = 35;
const int pinQ1 = 32;
const int pinQ2 = 33;
const int pinLED = 16;

const int freq = 5000;
const int ledChannel = 0;
const int Q1Channel = 1;
const int Q2Channel = 2;
const int resolutionLedChannel = 8;
const int resolutionQ1dChannel = 8;
const int resolutionQ2Channel = 8;


float cel, cel1, degC, degC1;
const float upper_temperature_limit = 55;

float Q1 = 0;
float Q2 = 0;
int iwrite_max = 225;
int iwrite_min = 0;

void setup() {
  Serial.begin(baud);
  while (!Serial) {
    ;
  }

  ledcSetup(Q1Channel, freq, resolutionQ1Channel);

  ledAttachPin(pinQ1, Q1Channel);

  ledcSetup(Q2Channel, freq, resolutionQ2Channel);

  ledAttachPin(pinQ2, Q2Channel);

  ledcSetup(ledChannel, freq, resolutionLedChannel);

  ledAttachPin(pinLED, ledChannel);

  ledcWrite(Q1Channel,0);
  ledcWrite(Q2Channel,0);
  ledcWrite(ledChannel,0);
}



void Q1on(){
  ledcWrite(Q1Channel,iwrite_max/255*100);
}

void Q1off(){
  ledcwrite(Q1Channel,iwrite_min/255*100);
}

void Q2on(){
  ledcWrite(Q2Channel,iwrite_max/255*100);
}

void Q2off(){
  ledcwrite(Q2Channel,iwrite_min/255*100);
}

void ledon(){
  ledcWrite(ledChannel,iwrite_max/255*100);
}

void ledoff(){
  ledcwrite(ledChannel,iwrite_min/255*100);
}

void cektemp(){
  degC = analogRead(pinT1) * 0.322265625 ;
  cel = degC/10;
  degC1 = analogRead(pinT2) * 0.322265625 ;
  cel1 = degC1/10;

  Serial.print("Temperature: ");
  Serial.print(cel);
  Serial.print("Celcius: ");
  Serial.print(" ~ ");
  Serial.print(cel1);
  Serial.println("Celcius: ");
}

void loop() {
  cektemp();
  if (cel > upper_temperature_limit){
    Q1off();
    ledon();
  }
  else {
    Q1on();
    ledoff();
  }
  if (cel1 > upper_temperature_limit){
    Q2off();
    ledon();
  }
  else {
    Q2on();
    ledoff();
  }
  delay (100);
}