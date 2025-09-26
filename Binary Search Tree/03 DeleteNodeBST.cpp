
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    };
};

Node *deleteNode(Node *root, int target)
{

    Node *parent = nullptr;
    Node *current = root;

    while (current->data == target && current != nullptr)
    {
        if (current->data > target)
        {
            current = current->left;
        }
        else
        {
            current = current->left;
        }
    }

    // case 1 : target node is leaf node
    if()



}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    return 0;
}
