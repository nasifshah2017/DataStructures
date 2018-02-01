/* Filename: LAB 21.cpp
 * -------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSC 162
 * Date:   2016/03/24
 *
 * Purpose: This program gives output of the time, inserted by the user in three
 * formats of 24hr, Military and Standard.
 */



#include "time_class.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   Time t;

   cout << "Please enter times either in standard (2:10 a.m.) "
        << "or military (0210) format.\n";

   cin >> t;

   while (!cin.eof())
   {
      cout << basic    << "     24-hour : " << t
           << military << "     Military: " << t
           << standard << "     Standard: " << t << endl;

      cin >> t;
   }

   return 0;
}
