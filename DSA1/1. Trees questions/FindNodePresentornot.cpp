#include <iostream>
#include "Tree.cpp"
#include <queue>
using namespace std;

bool findNode(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == k)
    {
        return 1;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    return 0;
}