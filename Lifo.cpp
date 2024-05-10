#include <iostream>
using namespace std;

typedef int ElementType;
typedef int pos;

class stack
{
    int cap;
    pos top;
    ElementType *elements;

public:
    stack(int size = 10)
    {
        top = -1;
        cap = size;
        elements = new ElementType[cap];
    }

    void push(ElementType element)
    {
        if (isFull())
        {
            cout << "stack is full\n";
        }
        else
        {
            // top++;
            // elements[top] = element;
            elements[++top] = element;
        }
    }

    ElementType pop()
    {
        if (isEmpty())
        {
            cout << "Error : stack is Empty\n";
            return -1;
        }
        else
        {
            top--;
            return elements[top + 1];
            // return elemetns[top--];
        }
    }

    ElementType size()
    {
        return top;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == cap - 1;
    }

    ElementType Top()
    {
        if (isEmpty())
        {
            cout << "Error: the stack is Empty\n";
            return -1;
        }
        else
        {
            return elements[top];
        }
    }
};
int main()
{
    //for test the stack...
    // stack s;
    // s.push(5);
    // s.push(3);
    // cout<<s.Top()<<endl;
    // s.size();
    // int x = s.pop();
    // cout << x << endl;
    // s.isEmpty() ? cout << "Empty" << endl :cout << "Not Empty" << endl ;
    // int y = s.pop();
    // cout << y << endl;
    // s.isEmpty() ? cout << "Empty" << endl :cout << "Not Empty" << endl ;
    return 0;
}