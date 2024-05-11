#include <iostream>
using namespace std;

typedef int ElementType;

struct node
{
    ElementType element;
    node *next;
};

typedef node *pos;

class Queue
{
    pos front, rear;
    int counter;

public:
    Queue()
    {
        counter = 0;
        front = NULL;
        rear = NULL;
    }

    void enqueue(ElementType e)
    {
        node *newNode = new node;
        newNode->element = e;

        if (isEmpty())
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }
        rear = newNode;
        counter++;
    }

    ElementType dequeue()
    {
        if (!isEmpty())
        {
            ElementType out = front->element;
            front = front->next;
            counter--;
            return out;
        }
        else
        {
            cout << "Error : Queue is Empty\n";
            return -999999;
        }
    }

    ElementType First()
    {
        if (isEmpty())
        {
            cout << "Error : Queue is Empty\n";
            return -999999;
        }
        else
        {
            return front->element;
        }
    }

    bool isEmpty()
    {
        return counter == 0;
    }

    void print()
    {
        // cout << "counter :" << counter << endl;
        // for (int j = 0; j < counter; j)
        // {
        //     cout << "dequeue :" << dequeue() << endl;
        // }
        // cout << "counter :" << counter << endl;

        node *i = new node;
        i = front;
        while (i != rear->next)
        {
            cout << i->element << endl;
            i = i->next;
        }
    }
};
int main()
{
    // for test ...
    //  Queue x;    
    //  x.enqueue(4);
    //  x.enqueue(5);
    //  x.enqueue(9);
    //  x.enqueue(8);
    //  x.enqueue(3);
    //  x.enqueue(20);
    //  x.isEmpty() ? cout << "isEmpty\n" : cout << "NOt Empty\n";
    //  cout << x.First() << endl;
    //  cout << x.dequeue() << endl;
    //  x.isEmpty() ? cout << "isEmpty\n" : cout << "NOt Empty\n";
    //  cout << x.dequeue() << endl;
    //  x.isEmpty() ? cout << "isEmpty\n" : cout << "NOt Empty\n";
    //  x.print();
    //  x.isEmpty() ? cout << "isEmpty\n" : cout << "NOt Empty\n";

    return 0;
}