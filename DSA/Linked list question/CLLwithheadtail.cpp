#include <iostream>
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

class points
{
public:
    Node *head = NULL;
    Node *tail = NULL;
};

points takeInput()
{
    int data;
    cin >> data;
    points ans;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (ans.head == NULL)
        {
            ans.head = newNode;
            ans.tail = newNode;
            newNode->next = newNode;
        }

        ans.tail->next = newNode;
        ans.tail = ans.tail->next;
        ans.tail->next = ans.head;
        cin >> data;
    }
    return ans;
}

Node *inputLL()
{
    return takeInput().head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main()
{
    Node *head = inputLL();
    print(head);
    // points p1 = takeInput();
    // print(p1.head);
    return 0;
}