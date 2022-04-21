//      4 <- 3 <- 2 <- 1
// creating LL from front

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

class Stack
{
    int count = 0;
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = NULL;
            count = 1;
            return;
        }
        newNode->next = head;
        head = newNode;
        count++;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        int data = head->data;
        head = head->next;
        count--;
        return data;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return head->data;
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    2 cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    return 0;
}