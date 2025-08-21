#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // there are two cases for pushing a node in front,

    // CASE 1 :
    //  if head = NULL , then we will create a new node and point both head and tail to new node

    // CASE 2 :
    // if head != NULL , then we will create a new node, point new node's next address to head,
    // and then update head's address to new nodes address

    // Note:
    // newNode->next = head is same as (*newNode).next = head
    // -> arrow is shorthand for dereferencing

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // for printing a linked list:
    // we will take address of head in temp (bcoz head value should not change , else we will be not ablle to access ll again)

    // then we will loop through till temp is not null,

    // inside loop we will print temps value and change value of temp to next value in current node

    void print_ll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    // Pushing node at end

    // for pushing a node at end , two cases come along

    // CASE 1 : if tail == NULL , then we will just update heada and tail to new node's address

    // CASE 2 : tail != NUll then,

    // we will update tail's next value to new nodes address and shift tail pointer to new node.

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main()
{

    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(96);
    ll.print_ll();

    return 0;
}