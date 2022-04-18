#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // find how many number of elements are there in stack
    int size() { return nextIndex; }

    // check stack is empty or not;
    bool isEmpty() { return nextIndex == 0; }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (nextIndex == 0)
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
};

int main()
{
    StackUsingArray s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    return 0;
}