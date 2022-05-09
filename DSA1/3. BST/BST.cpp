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

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter the data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftNode = takeInput();
    BinaryTreeNode<int> *rightNode = takeInput();

    root->left = leftNode;
    root->right = rightNode;

    return root;
}

void print(BinaryTreeNode<int> *root)
{
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ",";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

BinaryTreeNode<int> *TakeinputLevelWise()
{
    int data;
    cout << "Enter the Root Data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftData;
        cout << "Enter the data of left node of " << front->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftData);
            root->left = leftNode;
            pendingNodes.push(leftNode);
        }

        int rightData;
        cout << "Enter the data of right node of " << front->data << " : ";
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightData);
            root->right = rightNode;
            pendingNodes.push(rightNode);
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
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
    return 0;
}