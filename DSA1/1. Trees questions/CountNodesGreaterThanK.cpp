#include <iostream>
#include "Tree.cpp"
using namespace std;

int countNode(TreeNode<int> *root, int element)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNode(root->children[i], element);
    }
    if (root->data > element)
    {
        return count + 1;
    }
    else
    {
        return count;
    }
}

int countNodes(TreeNode<int> *root, int element)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (root->data > element)
    {
        return count + 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i], element);
    }
    return count;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int count = countNodes(root, 5);
    cout << count;
    return 0;
}