#ifndef _time_class_h
#define _time_class_h

#include <iostream>

using namespace std;

class Time
{
   private:
      int hour;         // 24-hour clock hour value (range 0 - 23)
      int min;          // 24-hour clock minute value (range 0 - 59)

   public:
      Time(int h = 0, int m = 0) { hour = h; min = m; }   // constructor

      void setHour(int h) { hour = h; }                   // mutators
      void setMin(int m)  { min = m;  }

      int getHour() const { return hour; }                // accessors
      int getMin()  const { return min; }

      void displayBasic(ostream &)    const;    // 15:05  // output methods
      void displayMilitary(ostream &) const;    // 1505
      void displayStandard(ostream &) const;    // 3:05 pm
};

istream & operator >> (istream &, Time &);                // iostream methods
ostream & operator << (ostream &, const Time &);

ostream & basic(ostream &);                               // io manipulators
ostream & standard(ostream &);
ostream & military(ostream &);

#endif
