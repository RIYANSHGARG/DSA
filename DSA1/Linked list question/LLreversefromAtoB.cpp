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

class Pair
{
public:
    Node *head = NULL;
    Node *tail = NULL;
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

Pair TakeInput()
{
    int data;
    cin >> data;
    Pair p1;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (p1.head == NULL)
        {
            p1.head = newNode;
            p1.tail = newNode;
            p1.head->next = NULL;
        }
        p1.tail->next = newNode;
        p1.tail = p1.tail->next;
        p1.tail->next = NULL;
        cin >> data;
    }
    return p1;
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

Pair reverseAtPoints(Pair p1, int a, int b)
{
    Node *temp1 = p1.head;
    Node *temp2 = p1.head;
    int count1 = 1, count2 = 1;
    if (a == 1)
    {
        while (count2 != b)
        {
            temp2 = temp2->next;
            count2++;
        }
        Node *head = temp2->next;
        temp2->next = NULL;
        Node *head2 = reverseRecursion(p1.head);
        p1.head->next = head;
        p1.head = head2;
        return p1;
    }
    while (count1 != a - 1)
    {
        temp1 = temp1->next;
        count1++;
    }
    while (count2 != b)
    {
        temp2 = temp2->next;
        count2++;
    }
    Node *head2 = temp2->next;
    temp2->next = NULL;
    Node *first = temp1->next;
    temp1->next = reverseRecursion(temp1->next);
    first->next = head2;
    return p1;
}

int main()
{
    Pair p1;
    p1 = TakeInput();
    print(p1.head);
    int a, b;
    cin >> a >> b;
    Pair p2 = reverseAtPoints(p1, a, b);
    print(p2.head);
    return 0;
}