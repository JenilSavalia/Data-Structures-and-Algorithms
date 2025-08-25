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
    }
};

// Bullding a binary tree with help of Pre-Ordered Sequence
// Time Complexity: O(n)

// Recursive Function to Build Preorder Binaryy Tree

// Preorder : Root Left Right

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  // LEFT
    root->right = buildTree(preorder); // RIGHT

    return root;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    cout << root->data << endl;        // Output the root node's data
    cout << root->left->data << endl;  // Output the left child node's data
    cout << root->right->data << endl; // Output the right child node's data

    return 0;
}