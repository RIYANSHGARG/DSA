#include <iostream>
#include <vector>
#include "B-Tree.h"
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

vector<Node *> LevelWiseUsingLL(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        vector<Node *> v;
        return v;
    }
    Node *head = NULL;
    Node *tail = head;
    vector<Node *> v;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            tail->next = NULL;
            v.push_back(head);
            head = NULL;
            tail = NULL;
            if (q.size() == 0)
            {
                return v;
            }
            q.push(NULL);
            continue;
        }
        Node *newNode = new Node(front->data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = tail->next;

        if (front->left != NULL)
        {
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            q.push(front->right);
        }
    }
    return v;
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
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    vector<Node *> v = LevelWiseUsingLL(root);
    for (int i = 0; i < v.size(); i++)
    {
        print(v[i]);
    }
    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1