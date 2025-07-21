#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// ✅ Deleting a Node in a Binary Tree (Not BST)
// Here’s the general approach to delete a node (value key) in a binary tree:

// 🔁 Steps 1:
// Find the node to delete (target).
// Find the deepest and rightmost node (deepest).
// Replace target's data with deepest's data.
// Delete the deepest node.

       1
      / \
     2   3
        / \
       4   5

// 🔁 Step 2: Node Deletion in Binary Tree (Not BST)
// We'll follow the deepest-rightmost method:
// To delete a node with value X:
// Find the node to delete (X)
// Find the deepest-rightmost node (D)
// Replace X's value with D's value
// Delete node D

🎯 Example 1: Delete node 3
Step 1: Find node with value 3 → found
Step 2: Deepest-rightmost node = 5
Step 3: Replace 3 with 5
Step 4: Delete node 5


🔄 Updated Tree:

       1
      / \
     2   5
        / 
       4  



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

void deleteLeaf(Node* root, Node* delNode) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left) {
            if (curr->left == delNode) {
                curr->left = NULL;
                delete delNode;
                return;
            } else {
                q.push(curr->left);
            }
        }

        if (curr->right) {
            if (curr->right == delNode) {
                curr->right = NULL;
                delete delNode;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }
}

void NodeDeletionBinaryTree(Node *root,int key)
{
    queue<Node *> q;
    q.push(root);
    Node *temp1 = NULL;
    Node *temp = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data== key)
        {
            temp1 = temp;
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    if(temp1){
        int lastNodeData = temp->data;
        deleteLeaf(root,temp);
        temp1->data = lastNodeData;
    }
}



// print new binary tree after deletion
void LevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";
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

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    NodeDeletionBinaryTree(root,4);
    LevelOrder(root);
    return 0;
}