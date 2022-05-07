#include <iostream>
#include "1.TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    int size;
    cout << "Enter Number of children of " << root->data << " : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root data : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();
        int size;
        cout << "Enter number of children of " << front->data << " : ";
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            int childData;
            cout << "Data of children " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "Children of " << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            q.push(root->children[i]);
        }
        cout << endl;
    }
}
