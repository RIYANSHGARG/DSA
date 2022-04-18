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
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
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

Node *Midpoint(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = TakeInput();
    print(head);
    Node *Mid = Midpoint(head);
    cout << Mid->data;
    return 0;
}