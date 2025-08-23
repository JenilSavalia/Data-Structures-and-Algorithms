#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1];
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

