#ifndef INT_QUEUE_H_INCLUDED
#define INT_QUEUE_H_INCLUDED


class intQueue
{
    private:
        int  currentsize, arraysize, first, last;
        int *queueArray;
    public:
        intQueue(int s = 100);
        ~intQueue();
        intQueue(const intQueue& other);
        intQueue& operator=(const intQueue& other);

        bool enqueue(int);
        bool dequeue();
        int  front() const;

        bool Empty() const { return currentsize <= 0; }
        bool Full()  const { return currentsize >= arraysize; }
        int  Size()  const { return currentsize; }
};

#endif // INT_QUEUE_H_INCLUDED
