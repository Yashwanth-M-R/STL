#include <iostream>
#include <vector>
using namespace std;

//creating a template
template <class T>
//creating a custom stack using vector
class Stack
{
private:
    vector<T> Vector;

public:
    // Push, Pop, empty and size functions
    void push(T value)
    {
        Vector.push_back(value);
    }
    T pop()
    {
        T value = Vector.back();
        Vector.pop_back();
        return value;
    }
    bool empty()
    {
        return Vector.empty();
    }
    int size()
    {
        return Vector.size();
    }
};

int main()
{

    Stack<int> MyStack;
    // cutom push method
    MyStack.push(12);
    MyStack.push(24);
    MyStack.push(36);
    MyStack.push(48);
    MyStack.push(60);
    // displaying stack size
    cout << "Size of the stack : " << MyStack.size() << endl;
    // displaying stack contents
    while (!MyStack.empty())//checking if stack's empty
    {
        cout << MyStack.pop() << endl;
    }

    return 0;
}
