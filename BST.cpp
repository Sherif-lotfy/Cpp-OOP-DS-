#include <iostream>
#include "list"
useing namespace std;

struct Node
{
    int element;
    Node *left;
    Node *right;
    bool isExternal()
    {
        return (right == NULL && left == NULL);
    }
    list<Node *> children()
    {
        list<Node *> l;
        if (left != NULL)
            l.push_back(left);
        if (right != NULL)
            l.push_back(right);
        return l;
    }
};
typedef Node *pos;
class bst
{
public:
    pos root;
    // int counter;
    bst() { root = NULL; }
    bst(int e, pos l, pos r)
    {
        root->element = e;
        root->left = l;
        root->right = r;
    }
    void insert(pos &p, int element)
    {
        if (p->isExternal())
        {
            p = New Node(e, NULL, NULL)
        }
        else
        {
            if (e < p->element)
            {
                inset(p->left, e);
            }
            else
            {
                inset(p->right, e);
            }
        }
    }
    bool find(pos p, int e)
    {
        if (p == NULL)
        {
            return false;
        }
        else
        {
            if (e == p->element)
            {
                return true;
            }
            else if (e < p->element)
            {
                return find(p->left, e);
            }
            else
            {
                return find(p->right, e)
            }
        }
    }
   Node minNode(pos p){
    pos current = p;
    while(current->left !=NULL){
        current = current->left;
    }
    return current;
   }
    void Delete(pos p){
        if(p->left == NULL && p->right == NULL){
            p = NULL;
        }
        else if((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL)){
            if(p->right == NULL){

                //i have no idea...
                
            }
        }
        else if(p->left == NULL && p->right == NULL){
            pos minright = minNode(p->right);
            p->element = minright->element;
            minright = NULL;
        }
    }
};

int main()
{

    return 0;
}