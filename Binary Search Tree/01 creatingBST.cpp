

// in bst left sub tree's root element is smaller then root element and right sub tree's room element is greater then root element

// inorder traversal of BST gives sotred sequence

// Building BST from Array (unsorted)

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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    inorder(root);
    return 0;
}
