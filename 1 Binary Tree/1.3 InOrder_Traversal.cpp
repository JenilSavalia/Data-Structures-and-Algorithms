 #include <iostream>
#include <vector>
using namespace std;

class Node{
    
    public :
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// Bullding a binary tree with help of Pre-Ordered Sequence

// Recursive Function to Build Preorder Binaryy Tree
static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    
    if(preorder[idx]==-1){
        return NULL;
    }
    
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); // LEFT
    root->right = buildTree(preorder); // RIGHT
    
    return root;
    
    }
 


// InOrder Traversal -> Left -> ROOT -> Right (LDR)

 void inOrder(Node* root){
     if(root==NULL){
         return;
     }
     inOrder(root->left);
     cout << root-> data << endl;
     inOrder(root->right);
 }
 

int main() {
vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

Node* root = buildTree(preorder);
inOrder(root);
    return 0;
}