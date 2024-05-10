#include <iostream>
using namespace std;

// struct ele
// {
//     string name;
//     int id;
// };
typedef int ele;
struct Node
{
    ele element;
    Node *Next;
};

typedef Node *pos;

class List
{
    Node *head;
    Node *tail;
    int counter;

public:
    List()
    {
        makeNULL();
    }

    void insert(ele e, pos n)
    {
        if (n == NULL)
            n = End();
        Node *p = new Node;
        p->element = e;
        p->Next = n->Next;
        n->Next = p;
        if (p->Next == NULL)
            tail = p;
        counter++;
    }

    void makeNULL()
    {
        head = new Node;
        head->Next = NULL;
        tail = NULL;
        counter = 0;
    }

    pos First()
    {
        if (counter == 0)
        {
            return NULL;
        }
        else
        {
            return head;
        }
    }

    pos End()
    {
        if (head->Next == NULL)
            return head;
        return tail;
    }

    pos Next(pos p)
    {
        // if(p == tail)
        //     return NULL;  //it's not important coz if p == tail the compiler will return NULL automaticlly...
        return p->Next;
    }

    pos previous(pos p)
    {
        pos q = head;
        while (q->Next != p && q != NULL)
        {
            q = q->Next;
        }
        return q;
    }

    void Delete(pos p)
    {
        if (p->Next == tail)
        {
            tail = p;
            p->Next = NULL;
        }
        pos temp = p->Next;
        p->Next = p->Next->Next;
        temp->Next = NULL;
        delete temp;
        counter--;
    }

    pos locate(ele e)
    {
        pos p = head;
        while (p->Next != NULL)
        {
            if (p->Next->element == e)
                return p;
            p = p->Next;
        }
        return p;
    }

    ele retrive(pos p, bool &b)
    {
        if (p == NULL)
        {
            b = 0;
            return -9999999;
        }
        else
        {
            b = 1;
            return p->Next->element;
        }
    }

    void printList()
    {
        pos p = head;
        int i = 1;
        while (p->Next != NULL)
        {
            cout << "no." << i << " is : " << p->Next->element << endl;
            i++;
            p = p->Next;
        }
    }
};
int main()
{
    // for test...
    // List l;
    // l.insert(1, l.End());
    // l.insert(2, l.First());
    // l.insert(3, l.End());
    // l.insert(4, l.End());
    // l.insert(5, l.First());
    // l.insert(534, NULL);
    // l.printList();
    // cout << l.locate(2) << endl;
    // cout << l.locate(4) << endl;
    // if (l.locate(100) != l.End())
    //     cout << l.locate(100) << endl;
    // else{cout<<"not found";}

    return 0;
}