#include <iostream>
#include "BSTtemplate.h"
using namespace std;

BinaryTreeNode<int> *CreateBST(int *a, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + ((end - start) / 2);
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[mid]);
    BinaryTreeNode<int> *leftChild = CreateBST(a, start, mid - 1);
    BinaryTreeNode<int> *rightChild = CreateBST(a, mid + 1, end);

    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    BinaryTreeNode<int> *root = CreateBST(a, 0, size - 1);
    printLevelWise(root);
    return 0;
}

// 1 2 3 4 5 6 7

// 4 + 6 - 4