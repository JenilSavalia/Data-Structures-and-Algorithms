// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

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

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }
    void insert_at_head(int value)
    {
        Node *newNode = new Node(value);
        if (tail == NULL)
        {
            head = tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = head; // or newNode->next = tail->next
            head = newNode;
            tail->next = head;
        }
    }

    void insert_at_tail(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = tail->next; // or newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void delete_at_head()
    {
        if (head == NULL)
            return;
        else if (head == tail)
        { // case if only one node exists in list
            delete head;
            head = tail = NULL;
        }
        else
        {                      // 2 or more nodes exist in list
            Node *temp = head; // or  Node* temp = tail->next;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void delete_at_tail()
    {
        if (head == NULL)
            return;
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *prev = head;
            Node *temp = tail;
            while (prev->next != tail)
            { // or temp->next!=tail
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void print()
    {
        if (head == NULL)
            return;
        cout << head->data << "->";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
    }
};

int main()
{

    CircularList cll;
    cll.insert_at_head(1);
    cll.insert_at_head(2);
    cll.insert_at_head(3);
    cll.delete_at_tail();

    cll.print();
}