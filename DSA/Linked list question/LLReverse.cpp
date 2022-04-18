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
    // cout << tail->data << endl;
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

Node *reverse(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    while (cur != NULL)
    {
        Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

Node *reverseRecursion(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *rev = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return rev;
}

int main()
{
    Node *head = TakeInput();
    print(head);
    // Node *tail = reverse(head);
    // print(tail);
    // print(head);
    Node *tail = reverseRecursion(head);
    print(tail);
    return 0;
}