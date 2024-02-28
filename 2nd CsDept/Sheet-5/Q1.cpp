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
