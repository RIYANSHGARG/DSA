#include <iostream>
#include "Tree.cpp"
using namespace std;

int height(TreeNode<int> *root)
{
    int newheight = 0, oldheight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        newheight = height(root->children[i]);
        oldheight = (oldheight < newheight) ? newheight : oldheight;
    }
    return oldheight + 1;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int heights = height(root);
    cout << heights;
    return 0;
}