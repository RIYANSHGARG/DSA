#include <iostream>
#include "BSTtemplate.h"
using namespace std;

BinaryTreeNode<int> *DuplicateLeftChild(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    BinaryTreeNode<int> *leftNode = DuplicateLeftChild(root->left);
    BinaryTreeNode<int> *rightNode = DuplicateLeftChild(root->right);

    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    newNode->left = NULL;
    newNode->right = NULL;
    // BinaryTreeNode<int> *temp = root->left;
    if (root->left == NULL)
    {
        root->left = newNode;
        newNode->left = NULL;
        root->right = rightNode;
        return root;
    }

    root->left = newNode;
    newNode->left = leftNode;
    root->right = rightNode;
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    root = DuplicateLeftChild(root);
    print(root);
    return 0;
}
