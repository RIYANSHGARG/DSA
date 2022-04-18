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
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *head)
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

Node *Midpoint(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *Merging(Node *head1, Node *head2)
{
    Node *fh = NULL;
    Node *ft = NULL;
    if (head1->data <= head2->data)
    {
        fh = head1;
        ft = head1;
        head1 = head1->next;
    }
    else
    {
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            ft->next = head1;
            head1 = head1->next;
            ft = ft->next;
        }
        else
        {
            ft->next = head2;
            head2 = head2->next;
            ft = ft->next;
        }
    }
    (head1 == NULL) ? ft->next = head2 : ft->next = head1;
    return fh;
}

Node *MergeSort(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *slow = Midpoint(head);
    Node *head2 = slow->next;
    slow->next = NULL;
    head = MergeSort(head);
    head2 = MergeSort(head2);
    Node *finalHead = Merging(head, head2);
    return finalHead;
}

int main()
{
    Node *head = TakeInput();
    print(head);
    Node *SortedLL = MergeSort(head);
    print(SortedLL);
    return 0;
}