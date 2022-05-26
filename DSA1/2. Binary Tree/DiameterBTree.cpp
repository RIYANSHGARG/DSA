#include <iostream>
#include <algorithm>
#include <utility>
#include "BinaryTreeInput.cpp"
using namespace std;

class Pair
{
public:
    int height;
    int diameter;

    Pair()
    {
        height = 0;
        diameter = 0;
    }
};

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameterOfTree(root->left);
    int opt3 = diameterOfTree(root->right);

    return max(opt1, max(opt2, opt3));
}

// MY SOLUTION

// int heightDiameter(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         Pair p1;
//         return p1;
//     }
//     Pair left;
//     Pair right;
//     left.height = height(root->left);
//     right.height = height(root->right);
//     left = heightDiameter(root->left);
//     right = heightDiameter(root->right);

//     return max(left.height + right.height, max(left.Diameter, right.Diameter));
// }

// PRO SOLUTION

pair<int, int> heightdiameterpair(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftChild = heightdiameterpair(root->left);
    pair<int, int> rightChild = heightdiameterpair(root->right);

    // leftChild.first = left height and leftChild.second = left diameter

    pair<int, int> p;
    p.first = 1 + max(leftChild.first, rightChild.first);
    p.second = max(leftChild.first + rightChild.first, max(leftChild.second, rightChild.second));

    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    PrintLevelWise(root);
    // int diameter = diameterOfTree(root);
    // cout << diameter;

    pair<int, int> p = heightdiameterpair(root);
    cout << p.first << endl
         << p.second;
    return 0;
}

// 1 on left and 1 on right
// both in left
// both on right