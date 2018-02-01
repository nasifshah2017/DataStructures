#include "intQueue.h"
#include <iostream>
#include <cstdlib>

using namespace std;

intQueue::intQueue(int s)     // Constructor
{
    queueArray = new int[s];  // Dynamically allocate array
    arraysize = s;
    currentsize = 0;
    first = 0;
    last = -1;
}

intQueue::~intQueue()         // Destructor
{
    delete[] queueArray;      // Deallocate array
}

intQueue::intQueue(const intQueue& other) // Copy Constructor
{
    arraysize = other.arraysize;
    currentsize = other.currentsize;
    first = other.first;
    last = other.last;

    queueArray = new int[arraysize];    // Dynamically allocate array

    for (int i=0; i<arraysize; i++)     // Copy array contents
        queueArray[i] = other.queueArray[i];

}

intQueue& intQueue::operator=(const intQueue& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    arraysize = rhs.arraysize;
    currentsize = rhs.currentsize;
    first = rhs.first;
    last = rhs.last;

    delete [] queueArray;            // Deallocate old array

    queueArray = new int[arraysize]; // Dynamically allocate new one

    for (int i=0; i<arraysize; i++)  // Copy array contents
        queueArray[i] = rhs.queueArray[i];

    return *this;
}

bool intQueue::enqueue(int value)
{
    if (currentsize >= arraysize) return false;

    last = (last + 1) % arraysize;

    queueArray[last] = value;

    currentsize++;

    return true;
}

bool intQueue::dequeue()
{
    if (currentsize < 1) return false;

    first = (first + 1) % arraysize;

    currentsize--;

    return true;
}

int intQueue::front() const
{
    if (currentsize < 1)
    {
        cout << "Cannot take front of empty queue!\n";
        exit(0);
    }
    return queueArray[first];
}
