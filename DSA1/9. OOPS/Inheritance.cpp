#include <iostream>
using namespace std;

class Vehicle
{
public:
    string color;

protected:
    int numTyres;

private:
    int maxspeed;
};

class car : public Vehicle
{
public:
    int numGears;
    void setTyres()
    {
        numTyres = 4;
    }
    void print()
    {
        cout << "Color of car is : " << color << endl;
        cout << "gears of car is : " << numGears << endl;
        cout << "tyres of car is : " << numTyres << endl;
        // cout << "speed of car is : " << maxspeed;
    }
};

int main()
{
    Vehicle v;
    v.color = "blue";

    car c;
    c.color = "Black";
    c.numGears = 5;
    c.print();
    c.setTyres();
    c.print();
    return 0;
}