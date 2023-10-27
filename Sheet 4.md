#### Q1).
```
#include <iostream>
using namespace std;
class product {
private:
	string name;
	float price, tax;
	int serial;
	static int pserial;
public:
	product() {
		pserial -= 10;
		serial = pserial;
	}
	void read() {
		cout << "name of this product ? : ";
		cin >> name;
		cout << endl << "price ? : ";
		cin >> price;
		cout << endl << "tax (%) :";
		cin >> tax;
		cout << endl;
	}
	void display() {
		float net_price;
		net_price = price / (1 + tax);
		cout << "name is : " << name << endl
			<< "net_price is :" << net_price << endl
			<< "serial is : " << serial << endl;
	}
	void displayPserial() { cout << "pserial is : " << pserial; }
};
int product::pserial = 10000;
void main() {
	cout<<"Q1\n";
	product x, y, z;
	x.read();
	y.read();
	z.read();
	cout << endl;
	x.display();
	y.display();
	z.display();
	cout << endl;
	x.displayPserial();
}
```
---
#### Q2).
```
#include <iostream>
#include <math.h>
using namespace std;
class series {
	int x[20], n;
	double s[20];
public:
	series(int a) {
		n = a;
	}
	int fact(int x) {
		if (x <= 1) return 1;
		return x * fact(x - 1);
	}
	int combination(int a, int b) {
		return (fact(a) / (fact(a - b) * fact(b)));
	}
	void setx() {
		for (int i = 0;i < n;i++) {
			cout << "X" << i + 1 << " = ";
			cin >> x[i];
		}
	}
	int sum(int i) {
		int sum = 0;
		for (int j = 0;j <= i;j++) {
			sum += combination(i, j) * pow(x[i], j + 1);
			return sum;
		}
	}
	void setS() {
		int i;
		for (i = 0;i < n;i++)
			s[i] = sum(i);
	}
	void display() {
		cout << "i || S || X" << endl;
		for (int i = 0;i < n;i++)
			cout << i << " || " << s[i] << " || " << x[i] << endl;
	}
	friend int sumF(series);
	friend int compare(series, series);
};
int sumF(series S) {
	double max, min;
	max = min = S.s[0];
	for (int i = 0;i < S.n;i++) {
		if (max < S.s[i])max = S.s[i];
		if (min > S.s[i])min = S.s[i];
	}
	return max + min;
}
int compare(series X, series Y) {
	if (sumF(X) > sumF(Y))return sumF(X);
	return sumF(Y);
}
void main() {
	cout << "Q2\n";
	series A(4), B(6);
	A.setx();
	A.setS();
	cout << endl;
	B.setx();
	B.setS();
	cout << endl;
	cout << compare(A, B) << endl;
}
```
