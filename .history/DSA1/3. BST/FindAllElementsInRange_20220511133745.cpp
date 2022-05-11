#include <iostream>
#include "BSTtemplate.h"
using namespace std;

void FindAllNodes(BinaryTreeNode<int> *root, int start, int end)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > start && root->data < end)
    {
        FindAllNodes(root->left, start, root->data);
        FindAllNodes(root->right, root->data, end);
        cout << root->data << " ";
    }
    else if (root->data <= start && root->data < end)
    {
        FindAllNodes(root->right, start, end);
        if (root->data == start)
        {
            cout << root->data << " ";
        }
    }
    else if (root->data > start && root->data >= end)
    {
        FindAllNodes(root->left, start, end);
        if (root->data == end)
        {
            cout << root->data << " ";
        }
    }
}

void Print(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (NULL == root)
        return;
    if (k1 < root->data)
        Print(root->left, k1, k2);

    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";

    Print(root->right, k1, k2);
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    FindAllNodes(root, 6, 10);
    return 0;
}