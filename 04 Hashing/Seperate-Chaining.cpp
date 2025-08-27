#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

// class LinkedList
// {
// public:
//     Node *head;

//     LinkedList()
//     {
//         head = NULL;
//     }

//     void insertTail(int key, int value)
//     {
//         Node *newNode = new Node(key, value);
//         if (head == NULL)
//         {
//             head = newNode;
//         }
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
// };

class HashTable
{
public:
    Node *Htable[10] = {NULL};

    int hashFunction(int key)
    {
        return key % 10;
    }

    void insert(int key, int value)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        if (Htable[index] == NULL)
        {
            Htable[index] = newNode;
        }
        else
        {
            // Insert at tail
            Node *temp = Htable[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void search(int key)
    {
        Node *temp = Htable[hashFunction(key)];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << "Found: " << temp->key << " -> " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found." << endl;
    }
};

int main()
{
    HashTable h;
    h.insert(5, 85);
    h.insert(26, 36);
    h.insert(42, 888);
    h.insert(15, 5758);
    h.insert(36, 588);

    h.search(26);
}