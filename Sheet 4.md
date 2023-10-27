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
---
#### Q3)
```
#include <iostream>
using namespace std;
class YD;
class XD {
	float X[10];
	int n;
public:
	void read() {
		cout << "n =? ";
		cin >> n;
		for (int i = 0;i < n;i++) {
			cout << "X[" << i + 1 << "] = ";
			cin >> X[i];
		}
	}
	bool primeTest(float x) {
		if (x < 2)return 1;
		for (int i = 2;i < x;i++) {
			if ((int)x % i == 0) return 1;
		}
		return 0;
	}
	float avg() {
		int counter=0,sum=0;
		for (int i = 0;i < n;i++) {
			if (primeTest(X[i]) == 0) {
				sum += X[i];
				counter++;
			}
		}
		if (counter == 0) return 0;
		return(sum / counter);
	}
	int compare() {
		int Max=0;
		for (int i = 0;i < n;i++) {
			if (primeTest(X[i]) == 0) {
				Max = X[i];
				break;
			}
		}
		for (int i = 0;i < n;i++) {
			if (primeTest(X[i]) == 0) {
				if (Max < X[i])Max = X[i];
			}
		}
		return Max;
	}
	void display() {
		for (int i = 0;i < n;i++)
			cout << "X[" << i + 1 << "] = " << X[i] << endl;
	}
	friend class YD;
};
class YD {
	float Y[10];
	int a, m;
public:
	void read() {
		cout << "m = ";
		cin >> m;
		cout << "a = ";
		cin >> a;
		for (int i = 0;i < m;i++) {
			cout << "Y[" << i + 1 << "] = ";
			cin >> Y[i];
		}
	}
	float avg() {
		float sum = 0,counter=0;
		for (int i = 0;i < m;i++) {
			if ((int)Y[i] % a == 0) {
				sum += Y[i];
				counter++;
			}
		}
		return (sum / counter);
	}
	int compare() {
		int Max=0;
		for (int i = 0;i < m;i++) {
			if ((int)Y[i] % a == 0) {
				Max = Y[i];
				break;
			}
		}
		for (int i = 0;i < m;i++) {
			if ((int)Y[i] % a == 0) {
				if (Max < Y[i])Max = Y[i];
			}
		}
		return Max;
	}
	void display() {
		cout << "m = " << m << endl << "a =" << a << endl;
		for (int i = 0;i < m;i++)
			cout << "Y[" << i + 1 << "] = " << Y[i] << endl;
	}
	void Compare2(XD X) {
		if (X.avg() > avg()) {
			cout << endl << "The Max object is XD\n";
			X.display();
		}
		else if (X.avg() < avg()) {
			cout << endl << "The Max object is YD\n";
			display();
		}
		else
			cout << endl << "They are equal\n";
	}
	int max(XD X) {
		return (X.compare() + compare());
	}
};
void main() {
	XD X;
	YD Y;
	X.read();
	cout << endl;
	Y.read();
	cout << endl;
	Y.Compare2(X);
	cout << endl;
	cout << "(Max element in X)" << X.compare() << " + (Max element in Y)" << Y.compare() << " = " << Y.max(X);
	cout << endl;
}
```
