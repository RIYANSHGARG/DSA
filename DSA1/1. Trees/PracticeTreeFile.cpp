#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter root data : ";
    cin >> rootdata;
    cout << endl;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    int n;
    cout << "Enter number of children " << root->data << " : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootdata;
    cout << "Enter root data : ";
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        int n;
        cout << "Enter the number of children of " << front->data << " : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter the data of children " << i << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}

void print(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int countLeafNode(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countLeafNode(root->children[i]);
    }
    return count;
}

int totalNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += totalNodes(root->children[i]);
    }
    return count;
}

int heightOfTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int oldHeight = 0, newheight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        newheight = heightOfTree(root->children[i]);
        oldHeight = (oldHeight < newheight) ? newheight : oldHeight;
    }
    return oldHeight + 1;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    int leafNodes = countLeafNode(root);
    cout << leafNodes << endl;
    int TotalNodes = totalNodes(root);
    cout << TotalNodes << endl;
    int height = heightOfTree(root);
    cout << height << endl;
    return 0;
}