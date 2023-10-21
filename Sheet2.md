#### Q1)
Student.h
```
class Student {
private:
	string name;
	float age;
	int id;
	double tenMarks[10];
	float avg;
public:
	Student(string n,float a,int i) {
		name = n;
		age = a;
		id = i;
		for (int j = 0;j < 10;j++) {
			tenMarks[j] = 0;
		}
		avg = 0;
	}
	Student(Student& x) {
		name = x.name;
		age = x.age;
		id = x.id;
		for (int j = 0;j < 10;j++) {
			tenMarks[j] = x.tenMarks[j];
		}
		avg = x.avg;
	}
	void display() {
		cout << "name is : " << name << endl << "age is : " << age << endl << "id is : " << id << endl;
		for (int j = 0 ,avg=0;j < 10;j++) {
			cout << "grade no." << j + 1 << '=' << tenMarks[j] << endl;
			avg += tenMarks[j];
		}
		cout << "avrage is : " << avg << endl << endl;
	}
};
```
Student.cpp
```
#include <iostream>
using namespace std;
#include "Strudent.h"
void main() {
	Student A("Ahmed",19,123), B(A);
	cout << "mesa\n";
	A.display();
	B.display();
}
```
---
#### Q2)
Complex.h
```
class Complex {
private:
	float r, i;
public:
	Complex(int r=0, int i=0 ) :r(0), i(0){}
	Complex(Complex& X) {
		r = X.r;
		i = X.i;
	}
	void set() { cin >> r >> i; }
	void print() {
		if (r == 0 && i != 0)cout << i << 'i';
		else if (i == 0 && r != 0)cout << r;
		else if (i == 0 && r == 0)cout << 0;
		else cout << r << '+' << i << 'i';
		cout << endl << endl;
	}
	Complex convert() {
		cout << "convert\n";
		Complex A;
		A.r = sqrt(pow(r, 2) + pow(i, 2));
		A.i = 0;
		return A;
	}
	Complex multiplication (Complex X){
		cout << "multiplication\n";
		Complex A;
		A.r = (r * X.r) - (i * X.i);
		A.i = (r * X.i) + (i * X.r);
		return A;
	}
	Complex division(Complex X) {
		cout << "division\n";
		Complex A;
		A.r = ((r * X.r) + (i * X.i)) / (pow(X.r, 2) + pow(X.i, 2));
		A.i = ((i * X.r) - (r * X.i)) / (pow(X.r, 2) + pow(X.i, 2));
		return A;
	}
	Complex compare(Complex x,Complex y) {
		cout << "compare\n";
		Complex A=y, B=x;
		A = A.convert();
		B = B.convert();
		if (A.r > B.r)
			return y;
		return x;
	}
	Complex average(Complex A, Complex B) {
		cout << "average\n";
		Complex X;
		A = A.convert();
		B = B.convert();
		X.r = (A.r + B.r) / 2;
		return X;
	}
};
```
Complex.cpp
```
#include <iostream>
#include <math.h>
using namespace std;
#include "Complex.h"
void main() {
	Complex A,B,C,Max,avg;
	cout << "mesa\n";
	A.set();
	B.set();
	C = A.multiplication(B);
	C.print();
	C = A.division(B);
	C.print();
	C = A.convert();
	C.print();
	Max = Max.compare(A, B);
	Max.print();
	avg = avg.average(A,B);
	avg.print();
}
```
#### Q3)
Num.h
```
class Num {
private:
	float N[10];
	int m;
	string T[10];
public:
	int fact(float n) {
		int fact = n;
		for (int i = n-1;i > 0;i--)
			fact*= i;
		return fact;
	}
	int primeTest(float n) {
		if (n <= 1) return 0;
		for (int i = 2;i < n;i++) {
			if ((int)n % i == 0) return 0;
		}
		return 1;
	}
	void read() {
		cout << "length ? :";
		cin >> m;
		for (int i = 0;i < m;i++) {
			cout << 'N' << i + 1 << " =";
			do {
				cin >>N[i];
				if (N[i] < 0)cout << "try agin\n";
			} while (N[i] < 0);
			if (primeTest(N[i]) == 0) T[i] = "Not prime";
			else T[i] = "prime";
		}
	}
	void display() {
		for (int i = 0;i < m;i++)
			cout << "N[" << i + 1 << "] = " << N[i] << " : " << T[i] << endl;
	}
	int sumOfFacts() {
		cout << "Sum Of Factorials Of Prime Numbers\n";
		int sum = 0;
		for (int i = 0;i < m;i++) {
			if (T[i] == "prime")
				sum += fact(N[i]);
		}
		return sum;
	}
	float avgOfFacts() {
		cout << "Average Of Factorials Of Not-Prime Numbers\n";
		double avg = 0,counter=0;
		for (int i = 0;i < m;i++) {
			if (T[i] == "Not prime") {
				avg += fact(N[i]);
				counter++;
			}
		}
		avg /= counter;
		return avg;
	}
};
```
Num.cpp
```
#include <iostream>
using namespace std;
#include "Num.h"
void main() {
	Num A;
	A.read();
	A.display();
	cout << A.sumOfFacts() << endl;
	cout << A.avgOfFacts() << endl;
}
```
