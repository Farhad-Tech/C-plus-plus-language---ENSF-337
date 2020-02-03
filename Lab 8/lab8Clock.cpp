// File lab8Clock.h
// ENSF 337 Fall 2018,  LAB 8 - EXERCISE A
// By: M. Moussavi

#include <assert.h>
#include <string.h>
#include "lab8Clock.h"

Clock::Clock()
: hour(0), minute(0), second(0)
{
}

Clock::Clock(const int s)
: hour(0), minute(0), second(0)
{
  if (s>=0){
    sec_to_hms(s);
    //hour = s/3600;
  //  minute = (s%3600)/60;
  //  second = s%60;
  }
  if (hour>23){
    hour -= 24;
  }
}

Clock::Clock(const int h, const int m, const int s)
: hour(0), minute(0), second(0)
{
  if (s<0 || s>59 || m<0 || m>59 || h<0 || h>23){
    hour = 0;
    minute = 0;
    second = 0;
  } else {
    hour = h;
    minute = m;
    second = s;
    return;
  }
}

void Clock::increment() {
  second++;
  if (second>59){
    second %= 60;
    minute = second/60;
  }
  if (minute>59){
    minute %= 60;
    hour = minute/60;
  }
  if (hour>23){
    hour -= 24;
  }
}

void Clock::decrement() {
  second--;
  if (second<0){
    second = 59;
    minute --;
  }
  if (minute<0){
    minute = 59;
    hour --;
  }
  if (hour<0){
    hour = 23;
  }
}

void Clock::set_hour(int h) {
  if (h>=0 && h<=23)
    hour = h;
}

void Clock::set_minute(int m) {
  if (m>=0 && m<=59)
    minute = m;
}

void Clock::set_second(int s) {
  if (s>=0 && s<=59)
    second = s;
}

void Clock::add_seconds(int s) {
  if (s>0){
    second += s;
    if (second>59){
      minute = minute + second/60;
      second %= 60;
    }
    if (minute>59){
      hour = hour + minute/60;
      minute %= 60;
    }
    if (hour>23){
      hour %= 24;
    }
  }
}

int Clock::hms_to_sec(int h, int m, int s) {
  return (h*3600)+(m*60)+s;
}

void Clock::sec_to_hms(int n) {
  for (int i = 0; i<n; i++)
    increment();
}
