#include <iostream>
#include "BinaryTreeInput.cpp"
using namespace std;

BinaryTreeNode<int> *MirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    BinaryTreeNode<int> *leftChild = MirrorBinaryTree(root->left);
    BinaryTreeNode<int> *rightChild = MirrorBinaryTree(root->right);
    root->left = rightChild;
    root->right = leftChild;
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    PrintLevelWise(root);
    BinaryTreeNode<int> *newRoot = MirrorBinaryTree(root);
    PrintLevelWise(newRoot);
    return 0;
}