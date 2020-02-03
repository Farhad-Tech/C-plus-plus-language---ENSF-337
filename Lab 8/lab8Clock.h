// File lab8Clock.h
// ENSF 337 Fall 2018,  LAB 8 - EXERCISE A
// By: M. Moussavi

#ifndef lab8Clock_h
#define lab8Clock_h
#include <iostream>
using std::cout;
using std::endl;

class Clock {
public:
  Clock();

  Clock(const int s);

  Clock(const int h, const int m, const int s);

  void increment();
  void decrement();

  void add_seconds(int s);

  int get_hour() const {return hour;};
  int get_minute() const {return minute;};
  int get_second() const {return second;};

  void set_hour(int h);
  void set_minute(int m);
  void set_second(int s);

private:
  int hour;
  int minute;
  int second;

  int hms_to_sec(int h, int m, int s);

  void sec_to_hms(int n);
};

#endif
