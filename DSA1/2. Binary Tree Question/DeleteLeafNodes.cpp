#include <iostream>
#include "B-Tree.h"
using namespace std;

BinaryTreeNode<int> *DeleteLeafNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    BinaryTreeNode<int> *leftChild = DeleteLeafNode(root->left);
    BinaryTreeNode<int> *rightChild = DeleteLeafNode(root->right);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    // levelOrderTraversal(root);
    // cout<<endl;
    BinaryTreeNode<int> *newRoot = DeleteLeafNode(root);
    levelOrderTraversal(newRoot);
    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1