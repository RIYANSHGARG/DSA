#include <iostream>
#include "B-Tree.h"
using namespace std;

void levelOrderTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    levelOrderTraversal(root->left);
    cout << endl;
    levelOrderTraversal(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);

    levelOrderTraversal(root);

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1