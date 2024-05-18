#include <iostream>
using namespace std;

typedef int elementType;

struct Node
{
    elementType element;
    Node *left;
    Node *right;
    Node(elementType x = 0, Node *l = NULL, Node *r = NULL)
    {
        element = x;
        left = l;
        right = r;
    }
    bool isExternal(Node *p)
    {
        if (p->left == NULL && p->right == NULL)
        {
            return true;
        }
        return false;
    }
};
typedef Node *pos;

class BST
{
public:
    pos root;
    BST()
    {
        root = NULL;
    }
    void insert(pos &p, elementType e)
    {
        if (p == NULL)
        {
            p = new Node(e, NULL, NULL);
        }
        else
        {
            if (p->element > e)
            {
                insert(p->left, e);
            }
            else if (p->element < e)
            {
                insert(p->right, e);
            }
        }
        // if (p->element == e)
        // {
        //     return;
        // }
        // else if (p->element > e)
        // {
        //     if (p->left == NULL)
        //     {
        //         Node *newnode = new Node;
        //         p->left = newnode;
        //         newnode->element = e;
        //     }
        //     else
        //     {
        //         insert(p->left, e);
        //     }
        // }
        // else if (p->element < e)
        // {
        //     if (p->right == NULL)
        //     {
        //         Node *newnode = new Node;
        //         p->right = newnode;
        //         newnode->element = e;
        //     }
        //     else
        //     {
        //         insert(p->right, e);
        //     }
        // }
    }
    pos findMin(pos p)
    {
        if (p == NULL)
        {
            return NULL;
        }
        else
        {
            pos current = p;
            while (current->left != NULL)
            {
                current = current->left;
            }
            return current;
        }
    }
    void remove(pos &ptr, elementType elem)
    {
        if(ptr == NULL) return;
        if (ptr->element == elem){
            if (ptr->left != NULL && ptr->right != NULL)
            {
                pos p =  findMin(ptr->right);
                ptr->element = p->element;
                remove(ptr->right, p->element);
            }
            else
            {
                if (ptr->isExternal(ptr))
                {
                    ptr = NULL;
                }
                else if (ptr->left != NULL)
                {
                    pos discard = ptr;
                    ptr = ptr->left;
                    delete discard;
                }
                else
                {
                    pos discard = ptr;
                    ptr = ptr->right;
                    delete discard;
                }
            }
        }
        else if (ptr->element > elem)
            remove(ptr->left, elem);
        else
            remove(ptr->right, elem);
    }
    void inorder(pos p)
    {
        if (p != NULL)
        {
            inorder(p->left);
            cout << " " << p->element << " ";
            inorder(p->right);
        }
    }
    void preorder(pos p)
    {
        if (p != NULL)
        {
            cout << " " << p->element << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }
    void postorder(pos p)
    {
        if (p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout << " " << p->element << " ";
        }
    }
};

int main()
{
    BST t;
    t.insert(t.root, 4);
    t.insert(t.root, 2);
    t.insert(t.root, 1);
    t.insert(t.root, 3);
    t.insert(t.root, 6);
    t.insert(t.root, 5);
    t.insert(t.root, 7);
    cout << "\n minimum value in BST is: " << t.findMin(t.root)->element;
    cout<<endl;
    t.inorder(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.preorder(t.root);
    t.remove(t.root, 4);
    cout<<endl;
    t.inorder(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.preorder(t.root);
    system("pause");
    return 0;
}