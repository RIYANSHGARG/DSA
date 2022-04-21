// using DLL base file as a basic template;

#include <iostream>
#include "./DLL.cpp"
using namespace std;

Node *insert(Node *head, int data, int index)
{
    int count = 0;
    Node *newNode = new Node(data);
    if (index == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
        return head;
    }
    Node *temp = head;
    while (count != index - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int data, index;
    cin >> data >> index;
    head = insert(head, data, index);
    print(head);
    return 0;
}