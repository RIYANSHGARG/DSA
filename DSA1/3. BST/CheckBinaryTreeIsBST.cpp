#include <bits/stdc++.h>
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

// Method - 1

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

// Method - 2 (min , max , isbst)

pair<pair<int, int>, bool> checkingBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<pair<int, int>, bool> p;
        p.first.first = INT_MAX;
        p.first.second = INT_MIN;
        p.second = true;
        return p;
    }

    pair<pair<int, int>, bool> left = checkingBST(root->left);
    pair<pair<int, int>, bool> right = checkingBST(root->right);

    int leftmin = left.first.first;
    int leftmax = left.first.second;
    int rightmin = right.first.first;
    int rightmax = right.first.second;
    bool leftisBST = left.second;
    bool rightisBST = right.second;

    pair<pair<int, int>, bool> p;
    p.first.first = min(root->data, min(leftmin, rightmin));
    p.first.second = max(root->data, max(leftmax, rightmax));
    p.second = ((root->data > leftmax) && (root->data < rightmin) && leftisBST && rightisBST) ? true : false;

    return p;
}

// Method 3   (Top - Bottom approach)

bool isBSTTopBottom(BinaryTreeNode<int> *root, int Min = INT_MIN, int Max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < Min || root->data > Max)
    {
        return false;
    }
    bool leftisOK = isBSTTopBottom(root->left, Min, root->data - 1);
    bool rightisOK = isBSTTopBottom(root->right, root->data, Max);
    return leftisOK && rightisOK;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);

    // Method - 1
    // bool BST = isBST(root);
    // cout << BST;

    // Method - 2
    // pair<pair<int, int>, bool> p1;
    // p1 = checkingBST(root);
    // cout << p1.second;

    // Method - 3
    // bool check = isBSTTopBottom(root);
    // cout << check;

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
