#### Q1)
```
#include <iostream>
using namespace std;
class base {
protected:
	double B[30][30],X;
	int n;
public:
	base() {
		n = 0;
		X = 0;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++)
				B[i][j] = 0;
		}
	}
	void read() {
		cout << "length(n) is : ";
		cin >> n;
		cout << "X is : ";
		cin >> X;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				cout << "B["<<i + 1 << "]["<<j + 1 << "] = ";
				cin >> B[j][i];
			}
		}
		base::set();
	}
	double gcd(double a,double b) {
		if (a < 0)a *= -1;
		if (b < 0)b *= -1;
		double c = a;
		if (c > b) c = b;
		for (int i = c; i > 1; i--) {
			if ((int)a % i == 0 && (int)b % i == 0)
				return i;
		}
		return 1;
	}
	double maxGcd(int i) {
		double max = gcd(B[0][i], X);
		for (int j = 0; j < n - 1; j++) {
			if (max < gcd(B[j][i], X)) max = gcd(B[j][i], X);

		}
		return max;
	}
	void set() {
		for (int i = 0; i < n; i++) {
			B[n-1][i] = maxGcd(i);
		}
	}
	virtual double avg() {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += B[n-1][i];
		}
		return sum / n;
	}
	void display() {
		cout << "Average is : " << this->avg() << endl;
	}
};
class drive : public base {
	double D[30];
public:
	drive() {
		for (int i = 0; i < 30; i++)
			D[i] = 0;
	}
	double factorial(double s) {
		if (s < 0)s *= -1;
		if (s <= 1) return s;
		return s * factorial(s - 1);
	}
	void set() {
		for (int i = 0; i < n; i++) {
			D[i] = factorial(B[n - 1][i]);
		}
	}
	double avg() {
		drive::set();
		return (D[0] + D[n - 1]) / 2;
	}
};
void main() {
	base* p;
	drive x;
	p = &x;
	p->read();
	cout << "Base\n";
	base(x).display();
	cout << "Drive\n";
	p->display();
}
```
---
#### Q2)
```
#include<iostream>
#include<math.h>
using namespace std;
class base {
protected:
	double A[30], B[30], X;
	int n;
public:
	base() {
		n = 0;
		X = 0;
		for (int i = 0; i < 30; i++)
			A[i] = B[i] = 0;
	}
	double factorial(double a) {
		if (a <= 1)
			return a;
		return a * factorial(a - 1);
	}
	double combination(double a,double b) {
		if (b > a) {
			cout << "ERROR\n";
			return -1;
		}
		return factorial(a) / (factorial(a - b) * factorial(b));
	}
	void read() {
		cout << "length(n) is :";
		cin >> n;
		cout << "X is : ";
		cin >> X;
		for (int i = 0; i < n; i++) {
			cout << "A[" << i + 1 << "] = ";
			cin >> A[i];
			B[i] = combination(A[i], X);
		}
	}
	double max() {
		double m = B[0];
		for (int i = 0; i < n; i++) {
			if (m < B[i]) m = B[i];
		}
		return m;
	}
	double min() {
		double m = B[0];
		for (int i = 0; i < n; i++) {
			if (m > B[i]) m = B[i];
		}
		return m;
	}
	virtual double diff() {
		return max() - min();
	}
	void display() {
		cout << "Diff is : " << this->diff() << endl;
	}
};
class drive1 :virtual public base {
protected:
	double D1[30];
public:
	drive1() {
		for (int i = 0; i < 30; i++)
			D1[i] = 0;
	}
	void set() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++)
				D1[i] += (B[i] - A[i]);
		}
	}
	double diff() {
		drive1::set();
		int z = n / 2;
		double d = D1[z + 1] - D1[z];
		if (d < 0) d *= -1;
		return d;
	}
};
class drive2 :virtual public base {
protected:
	double D2[30];
public:
	drive2() {
		for (int i = 0; i < 30; i++)
			D2[i] = 1;
	}
	void set() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++)
				D2[i] *= (B[i] + A[i]);
		}
	}
	double diff() {
		drive2::set();
		double d = D2[n - 1] - D2[0];
		if (d < 0) d *= -1;
		return d;
	}
};
class drive : public drive1, public drive2 {
	double D[30];
public:
	drive() {
		for (int i = 0; i < 30; i++)
			D[i] = 0;
	}
	void set() {
		for (int i = 0; i < n; i++)
			D[i] = (A[i] * D1[i]) + (B[i] * D2[i]);
	}
	double diff() {
		set();
		double d = D[n - 1] - D[0];
		if (d < 0) d *= -1;
		return d;
	}
};
void main() {
	base* p;
	drive x;
	p = &x;
	p->read();
	cout << "Base\n";
	base(x).display();
	cout << "Drive1\n";
	drive1(x).display();
	cout << "Drive2\n";
	drive2(x).display();
	cout << "Drive\n";
	p->display();
}
```
---
#### Q3)
```
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
```
