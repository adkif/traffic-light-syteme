#include "TrafficLight.h"
#include "Led.h"

TrafficLight::TrafficLight(String tag, Vector<Led> leds){
  this->tag = tag;
  this->leds = leds;
  this->flag = 0;
  this->n = 0;
}

Led* TrafficLight::getLed(int i){
  return &this->leds.at(i);
}

void TrafficLight::setTag(String tag){
  this->tag = tag;
}

String TrafficLight::getTag(){
  return this->tag;
}

void TrafficLight::startCycle(){
  for(int i = 0; i<3; i++){
    Serial.print(this->leds[i].getTag());
    Serial.print(": ");
    Serial.print(this->leds[i].getAllowTime()/100);
    Serial.println(" secondes");
    this->leds[i].on();
    delay(this->leds[i].getAllowTime());
    this->leds[i].off();
  }
}

void TrafficLight::updateCycle(){
  Serial.println("detection");
  for(int i = 0; i<3; i++){
    if(this->leds[i].getTag() == "GREEN" && !this->flag){
      long increment = MIN_TIME + STEP * (n + 1);
      this->getLed(i)->setAllowTime(increment);
      if(this->leds[i].getAllowTime()>= LIMIT){
        this->flag = true;
      }
    }
   if(this->leds[i].getTag() == "RED" && !this->flag){
      long decrement = MAX_TIME - STEP * (n + 1);;
      this->getLed(i)->setAllowTime(decrement);
    }
  }
  this->n++;
}

void TrafficLight::resetCycle(){
  Serial.println("reset");
  for(int i = 0; i<3; i++){
    if(this->leds[i].getTag() == "RED"){
      this->getLed(i)->setAllowTime(MAX_TIME);
    }
    if(this->leds[i].getTag() == "GREEN"){
      this->getLed(i)->setAllowTime(MIN_TIME);
    }
  }
  this->flag = false;
  this->n = 0;
}
