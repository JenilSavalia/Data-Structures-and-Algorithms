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
        if (head == NULL)
            return;
        Node *temp = head; // taking copy of head
        head = head->next; // shifting head's position to second node

        if (head != NULL)
        {
            head->prev = NULL; // making prev value of second node "NULL"
        }

        temp->next = NULL; // making next value of front node "NULL"
        delete temp;       // deleting temp/front node
    }

    void pop_back()
    {
        if (head == NULL)
            return;

        Node *temp = tail;
        tail = tail->prev;

        if (head != NULL)
        {
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    void insert_node(int value, int position)
    {
        if (position < 0)
            return;
        if (position == 0)
        {
            push_front(value);
            return;
        }

        Node *temp = head;
        int index = 0;
        while (index != position - 1)
        {
            temp = temp->next;
            index++;
        }
        Node *newNode = new Node(value);
        newNode->prev = temp;
        newNode->next = temp->next;

        temp->next->prev = newNode;
        temp->next = newNode;
    }
};

int main()
{

    DoubleLL dll;

    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(4);
    dll.insert_node(6, 0);
    // dll.pop_back();
    dll.print();
}