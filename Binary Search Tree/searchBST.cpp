
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

Node *insert(Node *root, int val)
{

    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
};

Node *buildBST(vector<int> arr)
{

    Node *root = NULL;

    for (int val : arr)
    {
        root = insert(root, val);
    }

    return root;
};

bool searchBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data > target)
    {
        return searchBST(root->left, target);
    }
    else
    {
        return searchBST(root->right, target);
    }
}


// time complexicity of BST search is height of BST. 

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    cout << searchBST(root, 8);
    return 0;
}
