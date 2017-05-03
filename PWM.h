#ifndef PWM_h
#define PWM_h

#include "Arduino.h"

class PWM
{
  public:
    PWM(int out);
    int gen(long wide,long freq);
    unsigned long moment;
    long prevMomentH;
    long prevMomentL;
    long freq;
    int diff;
    int latch;
    boolean val;
  private:
    int _out;
};

#endif