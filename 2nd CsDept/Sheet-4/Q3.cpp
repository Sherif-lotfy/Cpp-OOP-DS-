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