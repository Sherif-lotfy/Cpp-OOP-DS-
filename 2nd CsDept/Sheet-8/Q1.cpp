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
