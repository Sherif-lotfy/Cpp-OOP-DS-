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