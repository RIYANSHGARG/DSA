#include <iostream>
#include "Tree.cpp"

using namespace std;

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
    cout << root->data << " ";
}

void Delete(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        Delete(root->children[i]);
    }
    delete root;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    preorder(root);
    // Delete(root);
    delete root;
    return 0;
}

// 4 5 2 6 3 1