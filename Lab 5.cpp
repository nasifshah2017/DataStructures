// Filename: LAB 17.cpp
// -------------------
// Author: Syed Nasif Ali Shah
// Course: CSci 162
// Date:   28/29 January 2016
//
// Purpose: This program simulates the time needed by the drunk chap
// to reach his home than he would take in his normal condition




#include "random.h"
#include <iostream>
#include <iomanip>


using namespace std;

//Function Declaration

int OneTrip(int);
void displayUser();
void simulator(int);


int main()
{
    displayUser();

return 0;
}

//Function: displayUser()
//Usage: Displaying to the user
//...............................

void displayUser()
{
    int singleTrip;

  for (int i = 2; i <= 7; i++)
  {
      simulator(i);
  }

  singleTrip = OneTrip(2);



  cout << " By taking only one trip the drunk fellow made it to block: power function :"
       << singleTrip
       << "\n";
}

//Function: simulator()
//Usage: To simulate the path
//............................

void simulator(int startingPoint)
{
    int value;
    double i, counter = 0, percentageHome;

    for(i = 0; i <= 1000; i++)
    {
      value = RandomInteger(startingPoint, 8);

      if (value == 8) counter++;
    }

    percentageHome = (counter/1000)*100;

    cout << "At starting point "
         << startingPoint
         << ", the drunk fellow made it to home "
         << setprecision(2)
         << percentageHome
         << "% of the time \n\n";

}

//Function: OneTrip()
//Usage: Reach home by one trip
//.............................

int OneTrip(int startingBlock)
{
    int x = RandomInteger(startingBlock, 8);

    return x;
}


