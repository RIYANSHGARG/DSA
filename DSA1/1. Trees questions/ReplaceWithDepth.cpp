#include <iostream>
#include "Tree.cpp"
using namespace std;

TreeNode<int> *replaceWithDepth(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->data = k;
    TreeNode<int> *newRoot;
    for (int i = 0; i < root->children.size(); i++)
    {
        newRoot = replaceWithDepth(root->children[i], k + 1);
    }
    return root;
}

TreeNode<int> *replaceWithDepthHelper(TreeNode<int> *root)
{
    int k = 0;
    TreeNode<int> *newRoot = replaceWithDepth(root, k);
    return newRoot;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    TreeNode<int> *newRoot = replaceWithDepthHelper(root);
    printTreeLevelWise(newRoot);
    return 0;
}