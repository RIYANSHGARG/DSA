#include <iostream>
#include "BinaryTreeInput.cpp"
using namespace std;

int heightOfTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int heightfromLeft = heightOfTree(root->left);
    int heightfromRight = heightOfTree(root->right);
    return (1 + ((heightfromLeft > heightfromRight) ? heightfromLeft : heightfromRight));
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    PrintLevelWise(root);
    int height = heightOfTree(root);
    cout << height;
    return 0;
}