/* Filename: Lab14.cpp
 * --------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSCI 162
 * Date:   28 January 2016
 * Purpose: This program asks user for the current month and outputs
 * all the others months sequentially till to the months before that.
 * The output is by the name of the month by taking the current month
 * as a number from the user.
 *
 */

 #include <iostream>

using namespace std;

enum MonthT {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

// Function Declaration

MonthT GetUser();
void PrintMonth (MonthT);
MonthT NextMonth (MonthT);


int main()
{
   MonthT term, m;
   cout << " Please enter a value for month  (Jan = 1, Feb = 2....)\n";


   term =  GetUser();
   cout << "\n";

   PrintMonth(term);

   cout << "\n";


   for (m = NextMonth(term); m != term;  m = NextMonth(m))
   {

       PrintMonth(m);
       cout << "\n";

   }



   return 0;
}

MonthT GetUser()
{
    int val;
    cin >> val;
    while (val < 1 || val > 12)
    {
         cout << " You have entered an invalid number \n";
         cin >> val;
    }

    return (MonthT) val;
}

void PrintMonth(MonthT mort)
{
   string name[] = {"","JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

   cout << name[mort];


}

MonthT NextMonth (MonthT shot)
{
    shot = (MonthT) (((shot % 12)) + 1);

    return shot;
}

