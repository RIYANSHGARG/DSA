#include <iostream>
#include <climits>
#include "BSTtemplate.h"
using namespace std;

int leftMaxNode(BinaryTreeNode<int> *root)
{
    int leftMax;
    // cout << leftMax;
    if (root->left == NULL && root->right == NULL)
    {
        leftMax = root->data;
        return leftMax;
    }
    leftMax = leftMaxNode(root->right);
    if (root->data < root->right->data)
    {
        leftMax = root->right->data;
        return leftMax;
    }
    return leftMax;
}

int rightMinNode(BinaryTreeNode<int> *root)
{
    int rightMin;
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    rightMin = rightMinNode(root->right);
    if (root->data < rightMin)
    {
        return root->data;
    }
    return rightMin;
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data <= rightMin) && (root->data > leftMax) && (isBST(root->left)) && (isBST(root->right));
    return output;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    bool BST = isBST(root);
    cout << BST;
    return 0;
}