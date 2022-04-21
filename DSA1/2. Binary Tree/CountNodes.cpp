#include <iostream>
#include "BinaryTreeInput.cpp"
using namespace std;

int countNode(BinaryTreeNode<int> *root)
{
    int countleft = 0, countright = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    countleft += countNode(root->left);
    countright += countNode(root->right);
    return countleft + countright + 1;
}

int countNodeShortcut(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodeShortcut(root->left) + countNodeShortcut(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    PrintLevelWise(root);
    int numOfNodes = countNode(root);
    cout << numOfNodes;
    return 0;
}