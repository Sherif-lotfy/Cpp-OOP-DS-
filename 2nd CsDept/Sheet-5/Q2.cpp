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