#include <iostream>
// #include "1.TreeNode.h"
#include "Tree.cpp"
using namespace std;

int numberOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += numberOfNodes(root->children[i]);
    }
    return count;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int count = numberOfNodes(root);
    cout << count;
    return 0;
}