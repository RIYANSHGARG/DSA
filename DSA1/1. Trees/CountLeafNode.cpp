#include <iostream>
#include "Tree.cpp"
using namespace std;

int countLeafNode(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countLeafNode(root->children[i]);
    }
    return count;
}

void printLeafNode(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printLeafNode(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int leafNode = countLeafNode(root);
    cout << leafNode << endl;
    printLeafNode(root);
    return 0;
}