#include <iostream>
#include "Tree.cpp"
using namespace std;

TreeNode<int> *rootChildMax(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    TreeNode<int> *maxroot = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxroot = rootChildMax(root->children[i]);
    }
    cout << maxroot->data;
    int newsum = maxroot->data;
    for (int i = 0; i < maxroot->children.size(); i++)
    {
        newsum += maxroot->children[i]->data;
    }
    ans = (newsum > sum) ? maxroot : ans;
    return ans;

    // vector<int> maxValues;
    // int oldsum = 0, newsum = 0;
    // TreeNode<int> *node = root;
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     oldsum += root->children[i]->data;
    // }
    // oldsum += root->data;
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     root = rootChildMax(root->children[i]);
    // }
    // if (oldsum < newsum)
    // {
    //     node = root;
    // }
    // return node;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    TreeNode<int> *node = rootChildMax(root);
    cout << node->data;
    return 0;
}