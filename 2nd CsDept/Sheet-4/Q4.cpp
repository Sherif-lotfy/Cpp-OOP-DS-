#include <iostream>
using namespace std;
	class NS;
	class Employee;
struct Data {
	string name;
	float salary, tax;
};
class Employee {
	Data E[10];
	int n;
public:
	void read() {
		cout << "n=? ";
		cin >> n;
		for (int i = 0;i < n;i++) {
			cout << "E" << i + 1 << ".Name is :";
			cin >> E[i].name;
			cout << "E" << i + 1 << ".Salary is :";
			cin >> E[i].salary;
			cout << "E" << i + 1 << ".Tax is :";
			cin >> E[i].tax;
			cout << endl << endl;
		}
	}
	void display() {
		for (int i = 0;i < n;i++) {
			cout << "E" << i + 1 << ".Name is :"
				<< E[i].name << endl
				<< "E" << i + 1 << ".Salary is :"
				<< E[i].salary << endl
				<< "E" << i + 1 << ".Tax is :"
				<< E[i].tax << endl
				<< endl << endl;
		}
	}
	friend class NS;
};
class NS {
	float nsl[10];
public:
	void set(Employee X) {
		for (int i = 0;i < X.n;i++) {
			nsl[i] = (X.E[i].salary / (1 + X.E[i].tax));
		}
	}
	double sum(Employee X) {
		double sum = 0;
		for (int i = 0;i < X.n;i++) {
			sum += nsl[i];
		}
		return sum;
	}
	void compare(NS A,Employee X,Employee Y) {
		if (sum(X) > A.sum(Y)) X.display();
		else if (sum(X) < A.sum(Y)) Y.display();
		else cout << endl << "they are equal\n";
	}

};
void main() {
	cout << "Q4\n";
	Employee X,Y;
	NS A, B;
	X.read();
	A.set(X);
	cout << endl;
	Y.read();
	B.set(Y);
	cout << endl;
	A.compare(B, X, Y);
	cout << endl;
}