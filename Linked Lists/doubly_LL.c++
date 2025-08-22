// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = prev = NULL;
    }
};

class DoubleLL
{
    Node *head;
    Node *tail;

public:
    DoubleLL()
    {
        head = tail = NULL;
    }

    void push_front(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "<=>";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        Node *temp = head;       // taking copy of head
        temp->next->prev = NULL; // making prev value of second node "NULL"
        head = temp->next;       // shifting head to second node
        temp->next = NULL;       // making next value of front node "NULL"
        delete temp;             // deleting temp/front node
    }
};

int main()
{

    DoubleLL dll;

    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(4);
    dll.pop_front();
    dll.pop_front();
    dll.print();
}