#include "Led.h"
#include "Arduino.h"

Led::Led(String tag, long allowTime, int pin){
  this->tag = tag;
  this->allowTime = allowTime;
  this->pin = pin;
  this->initialize();
}

void Led::setTag(String tag){
  this->tag = tag;
}

String Led::getTag(){
  return this->tag;
}
    
void Led::setAllowTime(long allowTime){
  this->allowTime = allowTime;
}
long Led::getAllowTime(){
  return this->allowTime;
}

void Led::setPin(int pin){
  this->pin = pin;
}
int Led::getPin(){
  return this->pin;
}

void Led::on(){
  digitalWrite(this->pin, HIGH);
}

void Led::off(){
  digitalWrite(this->pin, LOW);
}


void Led::initialize(){
  pinMode(this->pin, OUTPUT);
}
