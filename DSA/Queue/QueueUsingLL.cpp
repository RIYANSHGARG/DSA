#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class QueueUsingLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T front()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }
};

int main()
{
    QueueUsingLL<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    return 0;
}