#include <bits/stdc++.h>

using namespace std;

class Queue
{

private:
    int currSize;
    int maxSize;
    int start;
    int end;
    int *arr;

public:
    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }

        // If the queue is empty
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            // Move end forward in circular fashion
            end = (end + 1) % maxSize;
        }

        arr[end] = x;
        currSize++;
    }

    int pop()
    {
        if (currSize = 0)
        {
            cout << "Queue is Empty\nExiting..." << endl;
            exit(1);
        }

        int popped = arr[start]; // element to remove

        // If there's only one element left
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            // Move start forward circularly
            start = (start + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    int Top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int Size()
    {
        return currSize;
    }
};
