#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        int element = i + 1;
        v.push_back(element);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << v[i];
    }

    cout << endl
         << v.at(2) << endl;
    cout << v.capacity() << endl;
    return 0;
}