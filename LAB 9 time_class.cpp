#include "time_class.h"
#include <iostream>
#include <iomanip>

using namespace std;

typedef enum {BASIC, MIL, STD} flag_type;

static flag_type flag = BASIC;      // output flag

void Time::displayBasic(ostream &os) const     // This one works properly!
{
   os << hour << ':'              // first the hour (24 hour clock)
      << setfill('0')             // make sure minute 5 outputs as 05
      << setw(2) << min           // now the minute
      << setfill(' ');            // return to normal fill mode
}

void Time::displayMilitary(ostream &os) const
{  os << setfill('0')
      << setw(2)
      << hour
      << setfill('0')
      << setw(2) << min
      << setfill(' ');
   //displayBasic(os);       //  2. THIS IS NOT CORRECT! Output in Military format
}

void Time::displayStandard(ostream &os) const
{
   if (hour >= 12 && hour <= 24)
   {
       if (hour == 12)
       {



      os << hour   << ':'
      << setfill('0')
      << setw(2) << min
      << setfill(' ')
      << " PM";
       }
       else
       {
          os << hour -12  << ':'
      << setfill('0')
      << setw(2) << min
      << setfill(' ')
      << " PM";
       }
   }
   else if (hour <= 12)
   {
       if (hour == 0)
       {
           os << hour +12    << ':'
      << setfill('0')
      << setw(2) << min
      << setfill(' ')
      << " AM";
       }

   else
   {
       os << hour     << ':'
      << setfill('0')
      << setw(2) << min
      << setfill(' ')
      << " AM";
   }
   }

   else cout << " Wrong Input";



   //displayBasic(os);       //  3. THIS IS NOT CORRECT!
}

istream & operator >> (istream &cin, Time &t)
{
   int h, m;
   char ch, ampm[5], ap;
   cin >> dec >> h ;                 // get the hour (allow for leading 0)
   cin.get(ch);                     // what character follows hour?
   if (ch == ':')                   // is it a ':'?
   {
      cin >> m >> ampm;

      if (ampm [0] == 'a')
      {
          if (h == 12) h = 0;
      }
    else
    {
        if (h < 12) h = h + 12;// get minute and next non-space characters
                                    // assume either "a.m." or "p.m."

                        // 1. MUST DO SOMETHING HERE TO h
   }
   }
   else                             // must be military time in h
   {
      m = h % 100;
      h = h / 100;
   }
   t.setHour(h);
   t.setMin(m);

   return cin;
}

ostream & operator << (ostream &os, const Time &t)
{
   switch (flag)
   {
      case MIL: t.displayMilitary(os); break;
      case STD: t.displayStandard(os); break;
      default : t.displayBasic(os);    break;
   }
   return os;
}

ostream & basic (ostream &os)
{
   flag = BASIC;
   return os;
}

ostream & standard (ostream &os)
{
   flag = STD;
   return os;
}

ostream & military (ostream &os)
{
   flag = MIL;
   return os;
}
