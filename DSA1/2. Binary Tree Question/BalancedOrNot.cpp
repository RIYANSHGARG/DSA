#include <iostream>
#include <cstdlib>
#include "B-Tree.h"
using namespace std;

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return ((((abs(leftheight - rightheight)) <= 1) ? true : false) && isBalanced(root->left) && isBalanced(root->right));
}

// PRO LEVEL

pair<int, bool> isbalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> left = isbalanced(root->left);
    pair<int, bool> right = isbalanced(root->right);

    int lh = left.first;
    bool lib = left.second;
    int rh = right.first;
    bool rib = right.second;

    pair<int, bool> p;
    p.first = 1 + max(lh, rh);
    p.second = (((abs(lh - rh)) <= 1) && isbalanced(root->left).second && isbalanced(root->right).second) ? true : false;

    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    // bool TreeBalanced = isBalanced(root);
    // cout << TreeBalanced;

    pair<int, bool> p = isbalanced(root);
    cout << p.second;

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1