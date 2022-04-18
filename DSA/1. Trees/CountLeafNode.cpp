#include <iostream>
#include "Tree.cpp"
using namespace std;

int countLeafNode(TreeNode<int> *root)
{
    int count;
    if (root->children.size() == 0)
    {
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count = countLeafNode(root->children[i]);
    }
    return count;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int leafNode = countLeafNode(root);
    cout << leafNode;
    return 0;
}