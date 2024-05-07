#include <iostream>
using namespace std;

typedef int pos;


struct ele {
    string name;
    int id;
}
struct Node {
    ele element;
    Node *Next;
    
    void insert (ele e , pos P){
        List *p = new List;
        p -> element = e;
        p -> Next = P;
        L.previous(P) -> Next = p;
    }
};

