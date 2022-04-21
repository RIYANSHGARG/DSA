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

Node *TakeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
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

int findNode(Node *head, int element)
{
    int count = 0;
    Node *temp = head;
    if (head == NULL)
    {
        return -1;
    }
    if (head->data != element)
    {
        count = findNode(head->next, element);
        count != -1 ? count++ : -1;
    }
    return count;
}

int main()
{
    Node *head = TakeInput();
    print(head);
    int data;
    cin >> data;
    int a = findNode(head, data);
    cout << a;
    return 0;
}