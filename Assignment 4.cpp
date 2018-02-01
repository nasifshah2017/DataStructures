// Filename: Assignment 4.cpp
//------------------------------
// Author: Syed Nasif Ali (201304650)
// Course: CSCI 162
// Date: 05 April 2016
// Purpose: This program predicts number of gas pumps at a gas station
// by taking the number of cars and days from the user


#include <iostream>
#include <Queue>
#include "random.h"
#include "intQueue.h"

using namespace std;

#define customers 500
#define Days 10000

int main()
{
        int ArrivalTime = 0, service, wait = 0, counter;

        double TotalWaitTime = 0, AvgWaitTime;

        Randomize();

        for(int d = 0 ; d < Days ; d++)
        {
            queue <int> CustomersArrivalTime;
            queue <int> ServiceTime;


            TotalWaitTime = 0;
            ArrivalTime = 0; //Arrival Time of customers set to 0 at start of each day

            for (int i = 0; i < customers; i++)
            {
                ArrivalTime += RandomInteger(60, 180); //Assuming their arrival times

                //Assuming the the service time of customers and keeping it out of extreme range
                while ( (service = RandomNormal(570, 60) ) < 0 || service > 1000 );

                //Filling up the queue with customers' arrival times
                CustomersArrivalTime.push(ArrivalTime);

                // Storing their service times in a stack
                ServiceTime.push(service);

            }

            int ArrivalTimeNew, ServiceTimeNew;

            //Placing new customers at end of queue
            int ArrivalTimeOld = CustomersArrivalTime.front();
            int ServiceTimeOld = ServiceTime.front();
            int WaitOld = 0;

            //Discharging customers after they are done
            CustomersArrivalTime.pop();

            // Erasing leaving customers' service time
            ServiceTime.pop();

             //To count how many cars leave after 10 mins
             counter = 0;

            //Checking if pump is empty
            while(!CustomersArrivalTime.empty())
            {
                //Setting customers' arrival time as new time at the queue
                ArrivalTimeNew = CustomersArrivalTime.front();
                //Setting their service time as new in the queue
                ServiceTimeNew = ServiceTime.front();

                CustomersArrivalTime.pop();
                ServiceTime.pop();


                //Waiting time for arrival customers
                wait =  WaitOld + ArrivalTimeOld + ServiceTimeOld - ArrivalTimeNew;

                //Assuming customers are leaving after waiting 10 mins
                if(wait > 600)
                {
                    counter++;
                    continue;
                }

                if (wait > 0)
                    TotalWaitTime += wait; // Adding up the wait time

                ArrivalTimeOld = ArrivalTimeNew;
                ServiceTimeOld = ServiceTimeNew;
                WaitOld = wait;

            }
            //Average waiting time of customers
            AvgWaitTime = ((TotalWaitTime)/(customers - counter));

    }

    //Average wait time and number of cars leaving decreases
    //proportionally as we add pumps in the station
    for (int i = 1; i<8; i++)
        {
            cout << "If we have " << i
                 << " pumps then "
                 << "Average waiting time: "
                 << AvgWaitTime / i << " seconds\n\n"
                 << "Number of cars leaving without service after 10 mins: "
                 << counter / i
                 << " cars\n\n";
        }






    return 0;
}
