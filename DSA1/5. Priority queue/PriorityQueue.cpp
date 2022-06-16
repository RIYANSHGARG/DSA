// Heap Sort

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (pq.size() == 0)
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {

            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int Delete()
    {
        if (pq.size() == 0)
        {
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int childIndex = 0;

        while (2 * childIndex + 1 < pq.size())
        {
            int leftIndex = 2 * childIndex + 1;
            int rightIndex = 2 * childIndex + 2;

            if (pq[leftIndex] < pq[childIndex] && pq[leftIndex] < pq[rightIndex])
            {
                int minIndex = leftIndex;
                int temp = pq[childIndex];
                pq[childIndex] = pq[leftIndex];
                pq[leftIndex] = temp;
                childIndex = minIndex;
            }
            else if (pq[rightIndex] < pq[childIndex] && pq[rightIndex] < pq[leftIndex])
            {
                int minIndex = rightIndex;
                int temp = pq[childIndex];
                pq[childIndex] = pq[rightIndex];
                pq[rightIndex] = temp;
                childIndex = minIndex;
            }
            else
            {
                break;
            }
        }

        // int leftIndex = 2 * childIndex + 1;
        // int rightIndex = 2 * childIndex + 2;
        // while (leftIndex < pq.size())
        // {
        //     int minIndex = childIndex;
        //     if (pq[minIndex] > pq[leftIndex])
        //     {
        //         minIndex = leftIndex;
        //     }
        //     if (pq[minIndex] > pq[rightIndex] && pq[rightIndex] < pq.size())
        //     {
        //         minIndex = rightIndex;
        //     }
        //     if (childIndex == minIndex)
        //     {
        //         break;
        //     }
        //     int temp = pq[minIndex];
        //     pq[minIndex] = pq[childIndex];
        //     pq[childIndex] = temp;

        //     childIndex = minIndex;
        //     int leftIndex = 2 * childIndex + 1;
        //     int rightIndex = 2 * childIndex + 2;
        // }

        return ans;
    }
};

void inplaceHeapSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (a[childIndex] < a[parentIndex])
            {
                int temp = a[childIndex];
                a[childIndex] = a[parentIndex];
                a[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int ans = a[0];
    a[0] = a[n - 1];
    a[n - 1] = ans;
}

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.getSize() << " ";
    cout << p.getMin() << endl;

    while (!p.isEmpty())
    {
        cout << p.Delete() << " ";
    }

    return 0;
}