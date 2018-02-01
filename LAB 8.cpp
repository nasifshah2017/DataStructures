/* Filename: LAB 21.cpp
 * -------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSC 162
 * Date:   2016/03/11
 *
 * Purpose: The program eliminates the third suitor from the line by
 * sending the first two at the back, and it keeps on doing that, until
 * the last suitor remains and he is declared the winner
 */





#include <cstdlib>
#include <iostream>
#include "intQueue.h"
using namespace std;

int main() {

    int SuitorsNum;

    SuitorsNum = 2;

    while (SuitorsNum < 21)
    {
        int counter = 1;


        intQueue myQueue(SuitorsNum); //Fixing the number of Suitors


        for (int i = 1; i <= SuitorsNum; i++) // Filling up the queue
        {
            myQueue.enqueue(i);
        }

        for (int QueueSize = myQueue.Size(); QueueSize > 1; QueueSize--) // Sending the first two guys at the back and eliminating the third guy
            {  // When the size of Queue is 1, the loop breaks, and the last guy is the winner

                int Eliminator = counter % 3;

          if (Eliminator == 0)
            {
                myQueue.dequeue(); // Eliminating the third guy
            }
            else
            {
                int front_value = myQueue.front();
                myQueue.dequeue();
                myQueue.enqueue(front_value);
            }

            counter++;
        }
        cout << myQueue.front() << ' ';
        SuitorsNum++;
    }
    return 0;
}





