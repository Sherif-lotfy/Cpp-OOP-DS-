#include <iostream>
using namespace std;

struct book
{
    string name;
    float price;
};

int
main()
{
    book *x = new book;
    x->name = "lows of power";
    // cout << x->name;
    int *p , a;
    p = &a;
    a = 10;
    // cout<<a; // 10
    // cout<< &a; //0x5ffe7c <-- the address of ( a )...
    // cout<< p;  //0x5ffe7c <-- the address that ( p ) is holding...
    // cout<< &p; //0x5ffe80 <-- the address of ( p ) itself...
    // cout<< *(&p); //0x5ffe7c <-- the value that ( p ) is holding " the address of ( a ) " ...
    // cout<< &(*(&a)); //0x5ffe7c
    
    return 0;
}

// ( & ) means Address...  <-- very very important note
// void swap (int x , int y){
//     int t = x;
//     cout<< x<< "  "<<&x<<endl;
//     x = y;
//     y = t;
//     // cout<<y<<"   "<<&y;
// }
// int main (){
//     int a = 10 , b =20;
//     cout<<a<<"   "<<&a;
//     swap(5,10);
//     // cout<<"a"<<a<<endl<<"b"<<b;
//     return 0;
// }
// int main (){
    // int x = 10;
    // int &b = x;
    // cout<<"this is x :"<<x<<endl;
    
    // int *p = new int ;
    // *p = 2;
    // cout<<"p is : "<<*p;
// }