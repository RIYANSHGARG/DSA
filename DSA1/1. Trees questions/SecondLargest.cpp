#include <iostream>
#include <climits>
#include "Tree.cpp"
using namespace std;

class Pair
{
public:
    int largest;
    int secondLargest;

    Pair()
    {
        largest = 0;
        secondLargest = 0;
    }
};

// Method Using Pair class

Pair SecondLargest(TreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair p1;
        return p1;
    }
    Pair p1;
    p1.largest = root->data;
    p1.secondLargest = 0;
    Pair p2;
    for (int i = 0; i < root->children.size(); i++)
    {
        p2 = SecondLargest(root->children[i]);

        if (p2.largest > p1.largest && p2.secondLargest == 0)
        {
            int x = p1.largest;
            p1.largest = p2.largest;
            p1.secondLargest = x;
        }
        else if (p2.largest < p1.largest && p1.secondLargest == 0)
        {
            p1.largest = p1.largest;
            p1.secondLargest = p2.largest;
        }
        else if (p2.largest > p1.largest && p2.secondLargest != 0)
        {
            int x = p1.largest;
            p1.largest = p2.largest;
            p1.secondLargest = (p2.secondLargest > x) ? p2.secondLargest : x;
        }
        else if (p2.largest < p1.largest && p1.secondLargest != 0)
        {
            p1.largest = p1.largest;
            p1.secondLargest = (p1.secondLargest > p2.largest) ? p1.secondLargest : p2.largest;
        }
    }
    return p1;
}

//  Method Using INT_MIN

TreeNode<int> *LargestElement(TreeNode<int> *root)
{
    TreeNode<int> *base = root;
    TreeNode<int> *largest = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        largest = LargestElement(root->children[i]);
        if (largest->data > base->data)
        {
            base = largest;
        }
    }
    return base;
}

int maxdata(TreeNode<int> *root)
{
    int maxans = root->data;
    int max = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        max = maxdata(root->children[i]);
        if (max > maxans)
        {
            maxans = max;
        }
    }
    return maxans;
}

int secondLargerhelper(TreeNode<int> *root)
{
    TreeNode<int> *newRoot = LargestElement(root);
    newRoot->data = INT_MIN;
    int secondmax = maxdata(root);
    return secondmax;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    // Pair p1 = SecondLargest(root);
    // cout << p1.secondLargest;

    int max = secondLargerhelper(root);
    cout << max;
    return 0;
}

// 1 2 2 3 2 4 5 2 6 7 -1 -1 -1 -1