#include <iostream>
#include "BinaryTreeInput.cpp"
using namespace std;

bool IsPresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    return ((root->data == x) || (IsPresent(root->left, x)) || (IsPresent(root->right, x)));
}

int main()
{
    int x;
    cin >> x;
    BinaryTreeNode<int> *root = takeInputLevelWise();
    PrintLevelWise(root);
    bool present = IsPresent(root, x);
    cout << present;
    return 0;
}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1