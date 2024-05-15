#include <iostream>
#include "list"
using namespace std;

typedef int ElementType;

struct Node
{
    Node *perant;
    Node *right;
    Node *left;
    ElementType element;
    Node()
    {
        perant = NULL;
        right = NULL;
        left = NULL;
        element = 0;
    }
    Node(ElementType e, Node *p, Node *r, Node *l)
    {
        element = e;
        perant = p;
        right = r;
        left = l;
    }
    bool isRoot(Node *p)
    {
        return p->perant == NULL;
    }
    bool isExternal()
    {
        return (right == NULL && left == NULL);
    }
    list<Node *> children(){
        list<Node *> l;
        if (left != NULL)
            l.push_back(left);
        if (right != NULL)
            l.push_back(right);
        return l;
    }
};

class BT
{
    Node *_root;
    int counter;

public:
    BT()
    {
        _root = NULL;
        counter = 0;
    }
    int size()
    {
        return counter;
    }
    bool Empty()
    {
        return _root == NULL;
    }
    Node *addRoot(ElementType e)
    {
        if (!Empty())
        {
            cout << "Error: the tree is not Empty\n";
        }
        else
        {
            _root = new Node(e, NULL, NULL, NULL);
        }
        return _root;
    }
    Node *addleft(ElementType e, Node *p)
    {
        if (p->left != NULL)
        {
            cout << "Error: p already has a left child\n";
        }
        else
        {

            Node *newNode = new Node;
            p->left = newNode;
            newNode->element = e;
            newNode->perant = p;
            newNode->left = NULL;
            newNode->right = NULL;
            counter++;
        }
        return p->left;
    }
    void attach(Node *p, BT t1, BT t2)
    {
        if (!p->isExternal())
        {
            cout << "Error: p is not external\n";
        }
        else
        {
            p->left = t1._root;
            p->right = t2._root;
            t1._root->perant = p;
            t2._root->perant = p;
            counter += (t1.size() + t2.size());
        }
    }
};
int main()
{

    return 0;
}