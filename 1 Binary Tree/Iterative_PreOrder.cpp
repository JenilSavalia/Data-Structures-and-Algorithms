#include <iostream>
#include <vector>
using namespace std;

vector<int> preorderTraversal(TreeNode *root)
{

    if (root == NULL)
        return {};
    vector<int> result;
    stack<TreeNode *> treeStack;
    TreeNode *currNode;
    treeStack.push(root);

    while (treeStack.empty() == false)
    {
        currNode = treeStack.top();
        treeStack.pop();

        result.push_back(currNode->val);

        if (currNode->right != NULL)
            treeStack.push(currNode->right);

        if (currNode->left != NULL)
            treeStack.push(currNode->left);
    }
    return result;
}