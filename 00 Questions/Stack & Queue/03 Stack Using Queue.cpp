class MyStack
{
public:
    queue<int> que;

    void push(int x)
    {
        int size = que.size();
        que.push(x);
        for (int i = 0; i < size; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }

    // how this works is;
    // every time we push an element to queue, we reverse the queue
    // ex:   queue -> empty
    // queue.push(1)      queue -> 1
    // queue.push(2)
    // now we reverse the elements , that is we push the element to back , let say   ~  queue -> 1 2
    // then we will add top of queue to back and pop thet element
    // queue -> 2 1

    // queue.push(3)      queue -> 2 1 3
    // element 3 is  most recent element
    // element 2 2nd most recent element
    // element 1 3rd most recent element

    // again we have added 3 to queue and now we will reverse the quque till size - 1;

    // queue -> 3 2 1

    // in short
    // we are rotating the queue elements in the for-loop to make the recently added
    // element appear at the front. This simulates the stack's LIFO behavior.

    // Reverse the order of the queue by rotating the front elements to the back.
    // This ensures the most recently added element will be at the front of the queue,
    // simulating the stack's Last In First Out (LIFO) behavior.

    int pop()
    {
        int n = que.front();
        que.pop();
        return n;
    }

    int top() { return que.front(); }

    bool empty() { return que.size() == 0; }
};
