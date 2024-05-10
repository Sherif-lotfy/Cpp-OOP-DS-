#include <iostream>
using namespace std;

typedef int pos;
typedef int element;
int cap = 10;
struct List
{
    int *elements = new int[cap];
    // int elements[10];
    int last;
    List()
    {
        last = -1;
    }
    void Insert(element x, pos p, List L)
    {
        if (last == cap - 1)
        {
            cout << "list is full\n";
        }
        else
        {
            for (int i = L.last; i >= p; i--)
            {
                L.elements[i + 1] = L.elements[i];
            }
            last++;
            L.elements[p] = x;
        }
    }
    void Delete(pos p, List L)
    {
        if (last == -1)
        {
            cout << "the List is empty\n";
        }
        else if (p > L.last || p < 0)
        {
            cout << " pos is out of range\n";
        }
        else
        {
            for (int i = p; i < L.last; i++)
            {
                L.elements[i] = L.elements[i + 1];
            }
            last--;
        }
    }
    int FIRST(List L)
    {
        return 0;
    }
    int END(List L)
    {
        return last + 1;
    }
    int NEXT(pos p, List L)
    {
        if (p >= cap - 1)
        {
            cout << "capacity is full\n";
        }
        else if (p > last + 1 || p < 0)
        {
            cout << "out of range\n";
        }
        else
        {
            return p + 1;
        }
    }
    int previous(pos p, List L)
    {
        if (p > last || p < 0)
        {
            cout << "p is out of range\n";
        }
        else if (p == 0)
        {
            cout << "p is the first element in the list";
        }
        else
        {
            return p - 1;
        }
    }
    pos Locate(element x, List L)
    {
        for (int i = FIRST(L); i <= last; i++)
        {
            if (L.elements[i] == x)
            {
                return i;
            }
        }
        return L.END(L);
    }
    element Retrieve(pos p, List L)
    {
        if (p > last || p < 0)
        {
            cout << "p is out of range\n";
            return -999999; // means there is no any element is this position...
        }
        else
        {
            return L.elements[p];
        }
    }
    void makeNull(List L)
    {
        last = -1;
    }
    void PRINTLIST(List L)
    {
        for (int i = L.FIRST(L); i <= last; i++)
        {
            cout << i << ". is: " << L.elements[i] << endl;
        }
    }
};
int main()
{
    //For Testing the List...
    // List L; // last = -1 last
    // L.Insert(9, L.FIRST(L), L);
    // L.Insert(20, L.END(L), L);
    // L.Insert(100, L.FIRST(L), L);
    // pos p = L.Locate(9, L);
    // cout << "9 exists at pos =" << p << endl;
    // cout << endl;
    // cout << endl;
    // L.PRINTLIST(L); // 100 9 20
    // cout << endl;
    // L.Delete(L.Locate(9, L), L);
    // L.PRINTLIST(L); // 100 20
    // cout << endl;
    // L.Delete(L.Locate(9, L), L); // pos is out of range
    // L.PRINTLIST(L);              // 100 20
    // return 0;
}