#ifndef MY_LED_H
#define MY_LED_H
#include "Arduino.h"

class Led {
  private:
    String tag;
    long allowTime;
    int pin;
  public:
    Led(String tag, long allowTime, int pin);
    void setTag(String tag);
    String getTag();
    
    void setAllowTime(long allowTime);
    long getAllowTime();

    void setPin(int pin);
    int getPin();

    void on();
    void off();

    void initialize();
};

#endif
