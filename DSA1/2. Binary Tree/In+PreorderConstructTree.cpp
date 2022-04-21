#include <iostream>
#include "BinaryTreeInput.cpp"
using namespace std;

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i < inE; i++)
    {
        if (rootData == in[i])
        {
            rootIndex = i;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, linS, linE, lpreE, lpreE);
    root->left = buildTreeHelper(in, pre, rinS, rinE, rpreE, rpreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    cout << "Enter values of inorder : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter values of preorder : ";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    BinaryTreeNode<int> *root = buildTree(a, b, n);
    PrintLevelWise(root);
    return 0;
}