#include <iostream>
using namespace std;

template <typename T>

class QueueUsingArray
{
    T *data;
    int frontIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    QueueUsingArray()
    {
        data = new T[4];
        frontIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = 4;
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
        if (size == capacity)
        {
            int j = 0;
            T *newData = new T[capacity * 2];
            for (int i = frontIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < frontIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            frontIndex = 0;
            nextIndex = capacity;
            capacity = capacity * 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (frontIndex == -1)
        {
            frontIndex++;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "queue is Empty";
            return 0;
        }
        return data[frontIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is already empty" << endl;
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            frontIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main()
{
    QueueUsingArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getsize() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}