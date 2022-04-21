#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int data;
    cout << "Enter the data :";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter the rootdata : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter Left child of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            q.push(leftChild);
        }

        cout << "Enter right child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;

        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            q.push(rightChild);
        }

        // BinaryTreeNode<int> *leftChild = takeInputLevelWise();
        // BinaryTreeNode<int> *rightChild = takeInputLevelWise();
        // q.push(leftChild);
        // q.push(rightChild);
        // front->left = leftChild;
        // front->right = rightChild;
    }
    return root;
}

void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

void PrintLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ",";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data << ",";
            q.push(front->right);
        }
        cout << endl;
    }
}

// int main()
// {
//     // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
//     // BinaryTreeNode<int> *Node1 = new BinaryTreeNode<int>(20);
//     // BinaryTreeNode<int> *Node2 = new BinaryTreeNode<int>(30);
//     // root->left = Node1;
//     // root->right = Node2;

//     BinaryTreeNode<int> *root = takeInputLevelWise();

//     PrintLevelWise(root);
//     return 0;
// }