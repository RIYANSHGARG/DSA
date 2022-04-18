#include <iostream>
#include <climits>

using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    
    public:
    
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }


    int size(){
        return nextIndex;
    }
    

    bool isEmpty(){
        return nextIndex == 0;
    }
    
    
    void push(int element){
        
        
        if(nextIndex == capacity)
        {
            int *newData = new int[2*capacity];
            for(int i =0 ; i<capacity ; i++)
            {
                newData[i] = data[i];
            }
            capacity*=2;
            delete [] data;
            data = newData;
        }
        
        data[nextIndex] = element;
        nextIndex++;
    }
    
    
    int pop(){
        if(nextIndex == 0)
        {
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    
    
    int top(){
        if(nextIndex == 0)
        {
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
    
    
};


int main()
{

    // StackUsingArray s(3);
    StackUsingArray s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); 
    s.push(70);
    
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;
    
    return 0;
}
