#include <iostream>
#include <vector>
#include <queue>
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

// Recursive Function to Build Preorder Binaryy Tree
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

// Levell Order Traversal -> Level by Level (BFS)
// Time Complexity: O(n)

void LevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();


        cout << curr->data << endl;
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

         1
        / \
       2   3
          / \
         4   5


int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    LevelOrder(root);
    return 0;
}
