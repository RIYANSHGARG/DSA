#include <iostream>
#include "Tree.cpp"
#include <queue>
using namespace std;

bool Identical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    bool check = true;
    if (root1 == NULL || root2 == NULL)
    {
        return (root1->data == root2->data);
    }
    if (root1->data != root2->data)
    {
        check = false;
        return check;
    }
    for (int i = 0, j = 0; i < root1->children.size(), j < root2->children.size(); i++, j++)
    {
        if (check == false)
        {
            break;
            return check;
        }
        check = Identical(root1->children[i], root2->children[j]);
    }
    return check;
}

int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();
    printTreeLevelWise(root1);
    //    printLevelWise(root2);
    bool check = Identical(root1, root2);
    cout << check;
    return 0;
}