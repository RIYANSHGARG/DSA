#include <iostream>
#include "BSTtemplate.h"
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *LLUsingBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Node *head = NULL;
        return head;
    }

    Node *newNode = new Node(root->data);

    Node *left = LLUsingBST(root->left);
    Node *right = LLUsingBST(root->right);

    if (left == NULL)
    {
        newNode->next = right;
        return newNode;
    }

    Node *temp = left;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = right;

    return left;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    Node *head = LLUsingBST(root);
    print(head);
    return 0;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1