#include "Arduino.h"
#include "PWM.h"

PWM::PWM(int out)
{
  pinMode(out, OUTPUT);
  _out = out;
}

int PWM::gen(long wide, long freq) 

{
  diff = freq - wide;
  latch=1;
  moment = micros();
  if(moment - prevMomentH > wide && prevMomentH != latch)
  {
    val = 0;
    prevMomentH = latch;
    prevMomentL = moment; 
  }
  if(moment - prevMomentL > diff && prevMomentL != latch)
  {
    val = 1;
    prevMomentH = moment;
    prevMomentL = latch;
  }
  digitalWrite(_out, val);
}
