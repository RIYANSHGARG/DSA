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

Node *inputNode(Node *head, int index, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;
    while (count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node *del(Node *head, int index)
{
    int count = 0;
    if (index == 0)
    {
        head = head->next;
    }
    else
    {
        Node *temp = head;
        while (count != index - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *temp1 = temp->next;
        if (temp1->next == NULL)
        {
            temp->next = NULL;
            free(temp1);
        }
        else
        {
            temp->next = temp1->next;
            free(temp1);
        }
    }
    return head;
}

int nodeLen(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

int main()
{
    // Node *head;
    // Node *n1 = new Node(10);
    // Node *n2 = new Node(20);
    // Node *n3 = new Node(30);
    // Node *n4 = new Node(40);
    // Node *n5 = new Node(50);

    // head = n1;
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;

    Node *Head1 = TakeInput();
    print(Head1);
    int length = nodeLen(Head1);
    cout << length;
    int index = 0, data = 0;
    cin >> index >> data;
    Head1 = inputNode(Head1, index, data);
    print(Head1);
    int delIndex;
    cin >> delIndex;
    Head1 = del(Head1, delIndex);
    print(Head1);
    return 0;
}