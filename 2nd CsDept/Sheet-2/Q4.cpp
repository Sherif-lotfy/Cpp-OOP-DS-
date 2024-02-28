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
			A.S1 += m * (Fi / (pow(pow(A.x, i) + (m*iJ), 0.5)));
			m *= -1;
		}
		if (i % 2 == 0) A.S2 += m * (Fi / (pow(pow(A.x, i) + (m*iJ), 0.5)));
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