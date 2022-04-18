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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair ReverseLL(Node *head)
{
    if (head->next == NULL || head == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair rev = ReverseLL(head->next);
    rev.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = rev.head;
    ans.tail = head;
    return ans;
}

Node *ReverseBetter(Node *head)
{
    return ReverseLL(head).head;
}

int main()
{
    Node *head = TakeInput();
    print(head);
    head = ReverseBetter(head);
    print(head);
    return 0;
}