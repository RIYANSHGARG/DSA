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

Node *takeInput()
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
}

Node *reverseatpoint(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *Tail = reverseatpoint(head->next);
    head->next->next = head;
    head->next = NULL;
    return Tail;
}

Node *convergeatpoint(Node *head, int index)
{
    int count = 0;
    Node *temp = head;
    if (head->next == NULL)
        return head;
    while (count != index - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *head1 = temp->next;
    temp->next = NULL;
    Node *head2 = reverseatpoint(head);
    head1 = reverseatpoint(head1);
    head->next = head1;
    return head2;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << endl
         << "reverse LL at point : ";
    int index;
    cin >> index;
    head = convergeatpoint(head, index);
    print(head);
    return 0;
}