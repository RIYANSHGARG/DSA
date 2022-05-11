#include <iostream>
#include "BSTtemplate.h"
using namespace std;

BinaryTreeNode<int> *FindNode(BinaryTreeNode<int> *root, int element)
{
    if (root->data == element)
    {
        return root;
    }
    else if (element < root->data)
    {
        FindNode(root->left);
    }
    else
    {
        FindNode(root->right);
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    return 0;
}

// 1, 2, 5, 1, 2, 2, 2 1, 1, 2, 2, 2, 2, 3, 5

//     int
//     main()
// {
//     int a[], b[];

//     int count = 1, j = 0;
//     sort(a);
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] != a[i + 1])
//         {
//             b[j] = count;
//             j++;
//             count = 1;
//         }
//         else
//         {
//             count++;
//         }
//     }
//     for (int i = 0; i < '/0'; i++)
//     {
//         if (b[i] == b[i + 1])
//         {
//             cout << "False";
//             return;
//         }
//         else
//         {
//             cout << "True";
//         }
//     }
// }

// 1122234444