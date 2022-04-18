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

int LengthLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}

points insertNodeLL(points p1, int data, int index)
{
    int count = 0;
    Node *newNode = new Node(data);
    Node *temp = p1.head;
    if (index == 0)
    {
        newNode->next = p1.head;
        p1.head = newNode;
        p1.tail->next = p1.head;
        return p1;
    }
    while (count != index - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return p1;
}

int main()
{
    // Node *head = inputLL();
    // print(head);
    points p1 = takeInput();
    print(p1.head);
    int data, index, length;
    cin >> data >> index;
    length = LengthLL(p1.head);
    points p2 = insertNodeLL(p1, data, (index % length));
    print(p2.head);
    return 0;
}