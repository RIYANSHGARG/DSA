#include <iostream>
#include "B-Tree.h"
using namespace std;

int SumOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (root->data + SumOfNodes(root->left) + SumOfNodes(root->right));
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    int sum = SumOfNodes(root);
    cout << "Total Sum is : " << sum;
    return 0;
}