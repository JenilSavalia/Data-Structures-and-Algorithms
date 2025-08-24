#include <iostream>
using namespace std;

// Queue follows FIFO principle,

// operations : PUSH to rear postion , POP from front postion, accessing node from FRONT
// all these above operations execute in O(1) time complexcity

//  enqueue  -> push
// dequeue -> pop

// Implementing Queue using Linkedlist

// front() : head->data
// push() : insert data at tail of LL
// pop() : remove data at head of LL

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int val) // insert data at tail of LL  O(1)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    { // remove data at head of LL
        if (head == NULL) return;
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    int front()
    {
        if (head == NULL) return -1;
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << " " << endl;
        q.pop(); 
    }
    return 0;
}