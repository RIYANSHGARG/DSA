#include <iostream>
#include <vector>
#include "BSTtemplate.h"
using namespace std;

vector<int> *findPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    vector<int> *v = new vector<int>();

    if (root->data == data)
    {
        v->push_back(root->data);
        return v;
    }
    else if (root->data > data)
    {
        v = findPath(root->left, data);
        if (v->size() != 0)
        {
            v->push_back(root->data);
        }
        return v;
    }
    v = findPath(root->right, data);
    if (v->size() != 0)
    {
        v->push_back(root->data);
    }
    return v;
}

int main()
{
    int data;
    cout << "Enter the data you want to find : ";
    cin >> data;

    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);

    vector<int> *v = findPath(root, data);
    for (int i = 0; i < v->size(); i++)
    {
        cout << v->at(i);
    }
    return 0;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1