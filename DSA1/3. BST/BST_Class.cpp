#include <iostream>
#include <climits>
#include "BSTtemplate.h"
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST(int data)
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    int Min(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return INT_MAX;
        }
        return min(root->data, min(Min(root->left), Min(root->right)));
    }
    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data = data)
        {
            return true;
        }
        else if (root->data > data)
        {
            return hasData(data, root->left);
        }
        else
        {
            return hasData(data, root->right);
        }
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newRoot = new BinaryTreeNode<int>(data);
            return newRoot;
        }
        if (data > root->data)
        {
            root->right = insert(data, root->right);
        }
        else
        {
            root->left = insert(data, root->left);
        }
        return root;
    }

    BinaryTreeNode<int> *Delete(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == data)
        {
            if (root->right == NULL && root->left == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int> *rightNode = root->right;
                root->right = NULL;
                delete root;
                return rightNode;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int> *leftNode = root->left;
                root->left = NULL;
                delete root;
                return leftNode;
            }
            else
            {
                int min = Min(root->right);

                // BinaryTreeNode<int> * minNode = root->right;
                // while(minNode-> left != NULL){
                //     minNode = minNode->left;
                // }
                // root->data = minNode->data;
                // root->right = Delete(min->data , root->right);
                // return root;

                root->data = min;
                root->right = Delete(min, root->right);
                return root;
            }
        }
        else if (data > root->data)
        {
            root->right = Delete(data, root->right);
            return root;
        }
        else
        {
            root->left = Delete(data, root->left);
            return root;
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void insert(int data)
    {
        root = insert(data, root);
        return;
    }
    void Delete(int data)
    {
        root = Delete(data, root);
        return;
    }
};

int main()
{

    return 0;
}

//     10
//   20  30
// 40 50   60

// 10
// 10 30
// 20 30 60
