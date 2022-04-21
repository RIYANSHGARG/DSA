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

Node *evenOdd(Node *head)
{
    Node *oh = NULL;
    Node *ot = NULL;
    Node *eh = NULL;
    Node *et = NULL;
    if (head == NULL)
    {
        return head;
    }

    while (head != NULL)
    {
        if (head->data % 2 != 0 && oh == NULL)
        {
            oh = head;
            ot = head;
            head = head->next;
            ot->next = NULL;
        }
        else if (head->data % 2 == 0 && eh == NULL)
        {
            eh = head;
            et = head;
            head = head->next;
            et->next = NULL;
        }
        else if (head->data % 2 != 0 && oh != NULL)
        {
            ot->next = head;
            head = head->next;
            ot = ot->next;
            ot->next = NULL;
        }
        else
        {
            et->next = head;
            head = head->next;
            et = et->next;
            et->next = NULL;
        }
    }
    if (oh == NULL)
    {
        return eh;
    }
    ot->next = eh;
    return oh;
}

int main()
{
    Node *head = TakeInput();
    print(head);
    head = evenOdd(head);
    print(head);
    return 0;
}