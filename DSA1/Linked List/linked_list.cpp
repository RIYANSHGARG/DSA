#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this.data = data;
        next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
}

int main()
{
    Node *head;
    Node n1(5);
    Node n2(6);
    Node n3(7);
    Node n4(8);
    Node n5(9);

    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    // while(data == -1)
    printList(head);
    // cout << n1.data << " " << n2.data;
    return 0;
}