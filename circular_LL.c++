// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node (int val){
        data = val;
        next = NULL;
    }
}

class CircularList{
    Node* head;
    Node* tail;
    
    CircularList(){
        head = tail = NULL;
    }
    
    void insert_at_head(int value){
        Node* newNode = new Node(value);
        if(tail == NULL){
            head = tail = newNode;
            tail->next = newNode;
        }else{
            newNode->next = head // or newNode->next = tail->next
            head = newNode;
            tail->next = head;
        }
    }
    
}


int main() {

CircularList cll;

}