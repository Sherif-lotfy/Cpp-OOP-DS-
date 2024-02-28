#include <iostream>
using namespace std;
class shape {
protected:
	float L, H;
public:
	shape() { L = H = 0; }
	void read() {
		cout << "L is : ";
		cin >> L;
		cout << "H is : ";
		cin >> H;
	}
	virtual float area() {	
		return 0;
	}
	void display() {
		cout << "area is : " << this->area()<<endl;
	}
};
class triangle :virtual public shape {
public:
	float area() {
		return L * H * 0.5;
	}
};
class square :virtual public shape {
public:
	float area() {
		return L * H;
	}
};
class Sqpyramid : public square, public triangle {
	float area() {
		return triangle::area() * 4 + square::area();
	}
};
void main() {
	shape* p;
	triangle x;
	square y;
	Sqpyramid z;
	p = &x;
	p->read();
	cout << "triangle ";
	p->display();
	p = &y;
	p->read();
	cout << "square ";
	p->display();
	p = &z;
	p->read();
	cout << "sqpyramid ";
	p->display();
}