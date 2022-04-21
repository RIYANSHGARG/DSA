#include <iostream>
#include <vector>
#include <queue>
#include "1.TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootdata;
    cout << "Enter root data :";
    cin >> rootdata;
    TreeNode<int> *rootNode = new TreeNode<int>(rootdata);

    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(rootNode);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        int n;
        cout << "Enter number of child " << front->data << " : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter the data of " << i << "th child of " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return rootNode;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data :";
    cin >> rootData;
    cout << endl;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of childrens of " << root->data << " : ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// int main()
// {
// TreeNode<int> *root = new TreeNode<int>(1);
// TreeNode<int> *node1 = new TreeNode<int>(2);
// TreeNode<int> *node2 = new TreeNode<int>(3);
// root->children.push_back(node1);
// root->children.push_back(node2);

// TreeNode<int> *root = takeInput();
// printTree(root);

//     TreeNode<int> *root = takeInputLevelWise();
//     printTreeLevelWise(root);

//     return 0;
// }