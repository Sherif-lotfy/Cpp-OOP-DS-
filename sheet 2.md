#### Q1)
```
#include <iostream>
using namespace std;
struct student {
	string name;
	float age;
	int Id;
	float tenGrades[10];
	float avg;
};
void read(student& A) {
	cout << "Name : ";
	cin >> A.name;
	cout << "Age : ";
	cin >> A.age;
	cout << "Id : ";
	cin >> A.Id;
	cout << "grades\n";
	for (int i = 0;i < 10; i++) {
		cout << i + 1 << " = ";
		cin >> A.tenGrades[i];
	}
	A.avg = 0;
	for (int i = 0;i < 10;i++)
		A.avg += A.tenGrades[i];
	A.avg /= 10;
}
void main() {
	student A[100];
	int n,m;
	cout << "sheet2.Q1\n";
	cin >> n;
	for (int i = 0;i < n;i++)
		read(A[i]);
	for (int i = 0; i < m;i++) {
		for (int j = 0; j < m - 1;j++) {
			if (A[i].avg < A[i + 1].avg) {
				student x = A[i];
				A[i] = A[i + 1];
				A[i + 1] = x;
			}
		}
	}
	cout << "Mini : \n"
		<< "Name : " << A[0].name << endl
		<< "Age : " << A[0].age << endl
		<< "Id : " << A[0].Id << endl
		<< "Average : " << A[0].avg << endl
		<< "Max : \n"
		<< "Name : " << A[n].name << endl
		<< "Age : " << A[n].age << endl
		<< "Id : " << A[n].Id << endl
		<< "Average : " << A[n].avg;
}
```
#### Q2)
```
#include <iostream>
using namespace std;
struct TTax {
	float price;
	float tax;
};
struct Toy {
	string Tname;
	TTax Tprice;
	float NetPrice;
};
void read(Toy& X) {
	cout << "TName is : ";
	cin >> X.Tname;
	cout << "price is : ";
	cin >> X.Tprice.price;
	cout << "tax (%) is : ";
	cin >> X.Tprice.tax;
	cout << endl;
	X.NetPrice = X.Tprice.price / (1 + (X.Tprice.tax / 100));
}
void display(Toy X) {
	cout << endl
		<< "TName : " << X.Tname << endl
		<< "Price : " << X.Tprice.price << " & tax : " << X.Tprice.tax << "%" << endl
		<< "Net_price : " << X.NetPrice << endl;
}
void main() {
	Toy A[100];
	int n;
	cout << "sheet2.Q2\n"
		<< "lenght of your array : ";
	cin >> n;
	for (int i = 0; i < n; i++)
		read(A[i]);
	for (int i = 0; i < n; i++) {
		if (A[i].NetPrice > 50)
			display(A[i]);
	}
}
```
#### Q3)
```
#include <iostream>
using namespace std;
struct GCD {
	int a, b, c;
};
void read(GCD& X) {
	do {
		cout << " a = ";
		cin >> X.a;
		if (X.a < 0)cout << "it must be positive.";
	} while (X.a < 0);
	do {
		cout << " b = ";
		cin >> X.b;
		if (X.b < 0)cout << "it must be positive.";
	} while (X.b < 0);
	cout << endl;
	int s = X.a;
	if (X.a > X.b) s = X.b;
	for (int i = 1;i <= s;i++)
		if (X.a % i == 0 && X.b % i == 0) X.c = i;
}
void display(GCD X) {
	cout << "GCD (" << X.a << "," << X.b << ")= " << X.c << endl;
}
void main() {
	GCD A[100];
	int n;
	cout << "sheet 2.Q3\n"
		<< "lenght = ";
	cin >> n;
	for (int i = 0;i < n; i++)
		read(A[i]);
	for (int i = 0;i < n; i++)
		display(A[i]);
}
```
#### Q4)
```
#include <iostream>
#include <math.h>
using namespace std;
struct Series {
	int n;
	float x;
	double S1, S2;
};
int factorial(int n) {
	int Fn=1;
	for (int i = 1;i <= n;i++)
		Fn *= i;
	return Fn;
}
void read(Series& A) {
	int m=1;
	cout << endl << "n : ";
	cin >> A.n;
	cout << "x :";
	cin >> A.x;
	A.S1 = 0;
	A.S2 = 0;
	for (int i = 1;i <= A.n;i++) {
		int Fi = factorial(i);
		if (i % 2 == 1) {
			A.S1 += m * (Fi / (pow(pow(A.x, i) + i, 0.5)));
			m *= -1;
		}
		if (i % 2 == 0) A.S2 += m * (Fi / (pow(pow(A.x, i) + i, 0.5)));
		Fi = 1;
		m *= -1;
	}
}
void display(Series A) {
	cout << "n : " << A.n << " & x : " << A.x << " & S1 : " << A.S1 << " & S2 :" << A.S2 << endl << endl;
}
void main() {
	Series A[3];
	cout << "sheet 2.Q4\n";
	for (int i = 0;i < 3;i++)
		read(A[i]);
	for (int i = 0;i < 3;i++)
		display(A[i]);
}
```
