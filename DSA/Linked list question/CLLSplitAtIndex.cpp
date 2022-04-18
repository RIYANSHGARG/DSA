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

Pair takeInput()
{
    int data;
    cin >> data;
    Pair ans;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (ans.head == NULL)
        {
            ans.head = newNode;
            ans.tail = newNode;
            newNode->next = ans.head;
        }
        ans.tail->next = newNode;
        ans.tail = ans.tail->next;
        ans.tail->next = ans.head;
        cin >> data;
    }
    return ans;
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

Pair SplitLL(Pair p1, int index)
{
    int count;
    Node *temp = p1.head;
    if (index == 0)
    {
        cout << "INDEX not valid";
        return p1;
    }
    while (count != index - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *head1 = temp->next;
    p1.tail->next = temp->next;
    temp->next = p1.head;
    print(p1.head);
    print(head1);
    return p1;
}

int main()
{
    Pair p1;
    p1 = takeInput();
    print(p1.head);
    int index, length;
    cin >> index;
    length = LengthLL(p1.head);
    Pair p2 = SplitLL(p1, (index % length));
    return 0;
}