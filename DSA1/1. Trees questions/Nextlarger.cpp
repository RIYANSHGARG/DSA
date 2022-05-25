#include <iostream>
#include <climits>
#include "Tree.cpp"
using namespace std;

int nextLargerElement(TreeNode<int> *root, int element)
{
    if (root == NULL)
    {
        return 0;
    }
    int oldLarger = (root->data > element) ? root->data : INT_MAX;
    int newLarger = 0, temp = INT_MAX;
    for (int i = 0; i < root->children.size(); i++)
    {
        newLarger = nextLargerElement(root->children[i], element);
        if (newLarger < temp)
        {
            temp = newLarger;
        }
    }
    if (temp < oldLarger)
    {
        oldLarger = temp;
        return oldLarger;
    }
    else if (oldLarger == INT_MAX)
    {
        return -1;
    }
    else
    {
        return oldLarger;
    }
}

int main()
{
    int element = 0;
    cin >> element;
    TreeNode<int> *root = takeInputLevelWise();
    int larger = nextLargerElement(root, element);
    cout << larger;
    return 0;
}