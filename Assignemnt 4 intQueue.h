#ifndef INT_QUEUE_H_INCLUDED
#define INT_QUEUE_H_INCLUDED

class intQueue
{
    private:
        int  currentsize, arraysize, first, last;
        int *queueArray;
    public:
        intQueue(int s = 100);                      // Constructor
        ~intQueue();                                // Destructor
        intQueue(const intQueue& other);            // Copy Constructor
        intQueue& operator=(const intQueue& other); // Assignment operator

        bool enqueue(int);                          // Add to end
        bool dequeue();                             // Remove from front
        int  front() const;                         // Get value at front

        bool Empty() const { return currentsize <= 0; }
        bool Full()  const { return currentsize >= arraysize; }
        int  Size()  const { return currentsize; }
};

#endif // INT_QUEUE_H_INCLUDED
