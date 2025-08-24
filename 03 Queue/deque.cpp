#include <iostream>
#include <deque>
using namespace std;

// Dequq is double ended queue where insertion in can be done from front and back, and pop also can be done from fornt and back,


int main()
{
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3); // 1,2,3

    q.push_front(4); // 4,1,2,3

    q.pop_back();
    return 0;
}