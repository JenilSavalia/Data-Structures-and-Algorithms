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

    void pop_front()
    {
        if (head == NULL)
            return;
        Node *front = head;
        head = front->next;
        front->next = NULL;

        delete front;
    }

    void pop_back()
    {
        // when there's only one node, then penultimate->next will be NULL, and NULL->next causes a crash., so this would avoi that
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        if (head == NULL)
            return;
        Node *penultimate = head;
        while (penultimate->next->next != NULL) // this will stop at second last node
        {
            // we will stop at second last node
            // so that we can delete last node
            // and update penultimate's next to NULL

            penultimate = penultimate->next;
        }
        Node *lastNode = penultimate->next;
        penultimate->next = NULL;
        delete lastNode;
        tail = penultimate;

        // in above while loop, if we have a tail pointer, we can use condition as while (penultimate->next == tail) ,
        // and store last second nodes data in temp pointer
    };

    void insert_node(int value, int position)
    {
        if (position < 0)
            return;
        if (position == 0)
        {
            push_front(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        int count = 0;
        while (count != position - 1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main()
{

    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(4);
    ll.push_front(5);

    // ll.push_back(96);
    // ll.pop_back();
    // ll.insert_node(6565,3);
    ll.print_ll();

    return 0;
}