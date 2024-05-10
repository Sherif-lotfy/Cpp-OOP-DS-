#include <iostream>
using namespace std;

typedef int ElementType;
typedef int pos;

class Queue
{
    ElementType *elements;
    int capacity, counter;
    pos front, rear;

public:
    Queue(int size = 10)
    {
        MakeNull(size);
    }
    void MakeNull(int size)
    {
        capacity = size;
        elements = new ElementType[capacity];
        counter = 0;
        front = 0;
        // front =-1; //previous codes...
        rear = -1;
    }
    void enqueue(ElementType element)
    {
        if (isFull())
        {
            cout << "Error: Queue is full\n";
        }
        else
        {
            // if (rear < capacity - 1)
            // {
            //     elements[++rear] = element;
            // }
            // else
            // {
            //     rear = 0;
            //     elements[rear] = element;
            // }
            rear = (rear + 1) % capacity;
            elements[rear] = element;
            // if(counter == 0){ front = 0; } //previous codes...
            counter++;
        }
    }
    ElementType dequeue()
    {
        if (isEmpty())
        {
            cout << "Error: the Queue is Empty\n";
            return -99999;
        }
        else
        {
            counter--;
            // if (front < capacity - 1)
            // {
            //     front++;
            //     return elements[front - 1];
            // }
            // else
            // {
            //     front = 0;
            //     return elements[capacity - 1];
            // }
            front = (front + 1) % capacity;
            return elements[front - 1];
        }
    }
    pos first()
    {
        if (isEmpty()) { return -999999; } else { return elements[front]; }
    }
    int Size() { return counter; }
    bool isEmpty() { return counter == 0; }
    bool isFull() { return counter == capacity; }
    void print()
    {
        for (pos q = front, i = 0; i < counter; i++, q = (q + 1) % capacity)
        {
            cout << "pos."<<q<<" = "<<elements[q]<<endl;
        }
    }
};
int main()
{
    //for test...
    // Queue q;
    // q.enqueue(10);
    // q.enqueue(20);
    // cout << " q.dequeue() is :" << q.dequeue() << endl;
    // cout << " q.dequeue() is :" << q.dequeue() << endl;
    // q.enqueue(4);
    // q.enqueue(7);
    // q.enqueue(3);
    // q.enqueue(1);
    // q.print();
    return 0;
}

// i have no idea why front has to start with -1...