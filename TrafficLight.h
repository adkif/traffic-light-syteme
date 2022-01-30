#ifndef MY_TRAFFICLIGHT_H
#define MY_TRAFFICLIGHT_H
#include "Led.h"
#include "Vector.h"
#define MAX_TIME 5400
#define MIN_TIME 300
#define LIMIT 4500
#define STEP 200

class TrafficLight {
  private:
    String tag;
    Vector<Led> leds;
    bool flag = false;
    int n;
  public:
    TrafficLight(String tag, Vector<Led> leds);
    Led* getLed(int i);
    void setTag(String tag);
    String getTag();
    void startCycle();
    void updateCycle();
    void resetCycle();
};

#endif
