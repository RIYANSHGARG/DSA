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
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = lpreS + linE - linS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE);
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
    cout << "Enter elements of inorder : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter elements of preorder : ";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    BinaryTreeNode<int> *root = buildTree(a, b, n);
    PrintLevelWise(root);
    return 0;
}