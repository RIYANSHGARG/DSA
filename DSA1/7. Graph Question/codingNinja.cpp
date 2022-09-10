#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char element;
            cin >> element;
            matrix[i][j] = element;
        }
    }
    return 0;
}