#include "TrafficLight.h"

// definir la broche 4 comme sortie du feu rouge 1
#define PINRED 4
// definir la broche 5 comme sortie du feu jaune 1
#define PINYELLOW 5 
// definir la broche 6 comme sortie du feu vert 1
#define PINGREEN 6
// definir la broche 2 comme entree du detecteur 1
#define DET1 2
// definir la broche 3 comme entree du detecteur 2
#define DET2 3

// definir un traffic light
Led ledsGroup[3] = {
  Led("RED",MAX_TIME,PINRED),
  Led("YELLOW",MIN_TIME,PINYELLOW),
  Led("GREEN",MIN_TIME,PINGREEN)
  };
Vector<Led> leds(ledsGroup, 3);
TrafficLight trafficLight = TrafficLight("Rond point TSONGO", leds);

void setup() {
  attachInterrupt(digitalPinToInterrupt(DET1), updateISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(DET2), resetISR, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.println(trafficLight.getTag());
  trafficLight.startCycle();
  Serial.println("================");
}

void updateISR(){
  trafficLight.updateCycle();
}

void resetISR(){
  trafficLight.resetCycle();
}
