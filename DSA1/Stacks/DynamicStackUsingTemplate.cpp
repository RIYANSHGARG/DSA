#include <iostream>
#include <climits>
using namespace std;

template <typename T>

class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    // find how many number of elements are there in stack
    int size() { return nextIndex; }

    // check stack is empty or not;
    bool isEmpty() { return nextIndex == 0; }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (nextIndex == 0)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
};

int main()
{
    StackUsingArray<char> s;
    s.push(97);
    s.push(98);
    s.push(99);
    s.push(100);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;

    return 0;
}