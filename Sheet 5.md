#### Q1)
```
#include <iostream>
using namespace std;
class product {
	float p[20], avg;
	int a, b, n;
public:
	product() {
		for (int i = 0; i < 20; i++)
			p[i] = 0.0;
		a = b = n = 0;
		avg = 0;
	}
	void read() {
		int counter = 0;
		cout << "length of this array = ";
		cin >> n;
		cout << "a = ";
		cin >> a;
		do {
			cout << "b = ";
			cin >> b;
			if (b < a)
				cout << "b must be greater than a\n";
		}while (b < a);
		for (int i = 0; i < n; i++) {
			cout << "p[" << i + 1 << "] = ";
			cin >> p[i];
			if (p[i] <= b && p[i] >= a) {
				avg += p[i];
				counter++;
			}
		}
		avg /= counter;
		cout << endl;
	}
	void display() {
		cout << "length = " << n << endl
			<< "a = " << a << endl
			<< "b = " << b << endl
			<< "average = " << avg << endl << endl;
	}
	product operator+(product A) {
		product S;
		 S.n = n;
		if (S.n < A.n) S.n = A.n;
		for (int i = 0; i < S.n; i++) {
			S.p[i] = p[i] + A.p[i];
		}
		return S;
	}
	bool operator > (product Z) {
		int l = n;
		if (l > Z.n) l = Z.n;
		for (int i = 0; i < l; i++) {
			if (p[i] < Z.p[i])
				return false;	
		}
		return true;
	}
	bool operator <(product Z) {
		if (avg < Z.avg) return true;
		return false;
	}
	float operator[](int x) { return p[x]; }
	friend product operator+(float tax, product X);
	int length() { return n; }
};
product operator+(float tax, product X) {
	product S;
	S.n = X.n;
	for (int i = 0; i < S.n; i++) {
		S.p[i] = X.p[i] + X.p[i] * tax;
	}
	return S;
}
void main() {
	product A, B, C, Tprice;
	float tax;
	A.read();
	B.read();
	(A < B) ? B.display() : A.display();
	C = A + B;
	cout << "tax(%) ?";
	cin >> tax;
	tax /= 100;
	Tprice = tax + C;
	for (int i = 0; i < Tprice.length(); i++)
		cout << "Tprice[" << i + 1 << "] =" << Tprice[i] << endl;
}
```
---
#### Q2)
```
#include <iostream>
#include <math.h>
using namespace std;
class Data {
	double D1[20], D2[20];
	int n;
public:
	Data() {
		n = 0;
		for (int i = 0; i < 20; i++) {
			D1[i] = 0;
			D2[i] = 0;
		}
	}
	int length() { return n; }
	void read() {
		cout << "Length(n) is : ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			cout << "D1[" << i+1 << "] is :";
			cin >> D1[i];
			if (D1[i] < 0) D1[i] *= -1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				D2[i] += (1 / pow(2, j)) * D1[j];
			}
		}
	}
	Data operator +=(Data x) {
		if (n < x.n) n = x.n;
		for (int i = 0; i < x.n; i++)
			D1[i] += x.D1[i];
		for (int i = 0; i < x.n; i++)
			D2[i] += x.D2[i];
		return *this;
	}
	//prefix
	Data operator++() {
		for (int i = 0; i < n; i++)
			D2[i]++;
		return *this;
	}
	//postfix
	Data operator++(int) {
		Data X = *this;
		for (int i = 0; i < n; i++)
			D2[i]++;
		return X;
	}
	double operator[](int x) { return D2[x]; }
	bool operator >(Data X) {
		int l = n;
		if (l > X.n) l = X.n;
		for (int i = 0; i < l; i++) {
			if (D2[i] < X.D2[i]) return false;
		}
		return true;
	}
	friend bool compare(Data X, Data Y);
};
bool compare(Data X, Data Y) {
	int l = X.n;
	if (l > Y.n)l = Y.n;
	for (int i = 0; i < l; i++) {
		if (Y[i] > X[i]) return true;
	}
	return false;
}
void main() {
	Data A, B, X, Y;
	A.read();
	B.read();
	X = ++A;
	Y = B++;
	if (compare(X, Y)) {
		cout << "the min object is the first one .\n";
		for (int i = 0; i < X.length(); i++) {
			cout << "X[" << i + 1 << "] = " << X[i] << endl;
		}
	}
	else {
		cout << "the min object is the second one .\n";
		for (int i = 0; i < Y.length(); i++)
			cout << "Y[" << i + 1 << "] = " << Y[i] << endl;
	}
	cout << "x+=Y\n";
	X += Y;
	for (int i = 0; i < X.length(); i++) {
		cout << "X[" << i + 1 << "] = " << X[i] << endl;
	}
}
```
---
#### Q3)
```
#include <iostream>
using namespace std;
class matrix {
	double M[10][10];
	int n, m;
public:
	matrix() {
		n = m = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				M[i][j] = 0;
		}
	}
	bool prime(double z) {
		if (z < 2) return false;
		for (int i = 2; i < z; i++) {
			if ((int)z % i == 0)return false;
		}
		return true;
	}
	void read() {
		cout << "No. of rows is : ";
		cin >> m;
		cout << "No. of columns is : ";
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				cout << "M[" << j + 1 << "][" << i + 1 << "] = ";
				cin >> M[j][i];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (M[i][j] > 0 && prime(M[i][j]))
					M[i][n - 1] += M[i][j];
			}
		}
	}
	void display() {
		cout << endl;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++)
				cout << "M[" << j + 1 << "][" << i + 1 << "] = " << M[j][i] << endl;
		}
		cout << endl;
	}
	double operator [] (int q) { return M[q][n - 1]; }
	friend matrix operator *(int constant , matrix X);
	bool operator >= (matrix A) {
		int z = m;
		if (z > A.m) z = A.m;
		for (int i = 0; i < z; i++) {
			if (M[i][n - 1] < A[i])
				return false;
		}
		return true;
	}
	matrix operator *(matrix A) {
		matrix B;
		if (n != A.m) {
			cout << "Multiplication can not be applied\n";
			B.m = m;
			B.n = n;
			return B;
		}
		B.m = m;
		B.n = A.n;
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				for (int k = 0; k < n; k++)
					B.M[j][i] += M[j][k] * A.M[k][i];
			}
		}
		return B;
	}
	int NoOfRows() { return m; }
};
	matrix operator *( int constant , matrix X) {
		matrix Zz;
		Zz.m = X.m;
		Zz.n = X.n;
		for (int i = 0; i < X.n; i++) {
			for (int j = 0; j < X.m; j++) {
				Zz.M[j][i] =constant *  X.M[j][i];
			}
		}
		return Zz;
	}
void main() {
	matrix X,Y,Z,C;
	X.read();
	Y.read();
	if (X >= Y) {
		X.display();
		Z = 5 * Y;
		cout << "Z = 5 * Y\n";
		for (int i = 0; i < Z.NoOfRows(); i++) {
			cout << "Z[" << i + 1 << "] = " << Z[i]<<endl;
		}
	}
	else {
		Y.display();
		Z = 2 * X;
		cout << "Z = 2 * X\n";
		for (int i = 0; i < Z.NoOfRows(); i++) {
			cout << "Z[" << i + 1 << "] = " << Z[i]<<endl;
		}
	}
	C = X * Y;
	C.display();
	for (int i = 0; i < C.NoOfRows(); i++) {
		cout << "C[" << i + 1 << "] = " << C[i] << endl;
	}
}
```
