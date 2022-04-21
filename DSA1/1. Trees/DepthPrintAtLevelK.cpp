#include <iostream>
#include "Tree.cpp"
using namespace std;

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int l;
    cout << "Enter the level of data or depth you wnted to print : ";
    cin >> l;
    printAtLevelK(root, l);
    return 0;
}