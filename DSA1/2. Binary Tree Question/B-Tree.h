#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootdata;
    cout << "Enter root data : ";
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftdata;
        cout << "Enter the left child of : " << front->data << " : ";
        cin >> leftdata;
        if (leftdata != -1)
        {
            BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(leftdata);
            front->left = leftchild;
            pendingNodes.push(leftchild);
        }

        int rightdata;
        cout << "Enter the right child of " << front->data << " : ";
        cin >> rightdata;
        if (rightdata != -1)
        {
            BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(rightdata);
            front->right = rightchild;
            pendingNodes.push(rightchild);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ",";
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data << ",";
            q.push(front->right);
        }
        cout << endl;
    }
}