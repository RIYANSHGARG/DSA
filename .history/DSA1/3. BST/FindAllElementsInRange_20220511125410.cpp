#include <iostream>
#include "BSTtemplate.h"
using namespace std;

void FindAllNodes(BinaryTreeNode<int> *root, int start, int end)
{
    if (root->data > start && root->data < end)
    {
        cout << root->data << " ";
        FindAllNodes(root->left, start, root->data);
        FindAllNodes(root->right, root->data, end);
    }
    else if (root->data < start && root->data <= end)
    {
        if (root->data == end)
        {
            cout << root->data << " ";
        }
        FindAllNodes(root->left, start, end);
    }
    else if (root->data >= start && root->data > end)
    {
        if (root->data == end)
        {
            cout << root->data << " ";
        }
        FindAllNodes(root->right, start, end);
    }
    // else
    // {
    //     return;
    // }
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    FindAllNodes(root, 5, 10);
    return 0;
}