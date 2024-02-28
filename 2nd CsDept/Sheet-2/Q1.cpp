#include <iostream>
using namespace std;
struct student {
	string name;
	float age;
	int Id;
	float tenGrades[10];
	float avg;
};
void read(student& A) {
	cout << "Name : ";
	cin >> A.name;
	cout << "Age : ";
	cin >> A.age;
	cout << "Id : ";
	cin >> A.Id;
	cout << "grades\n";
	for (int i = 0;i < 10; i++) {
		cout << i + 1 << " = ";
		cin >> A.tenGrades[i];
	}
	A.avg = 0;
	for (int i = 0;i < 10;i++)
		A.avg += A.tenGrades[i];
	A.avg /= 10;
}
void main() {
	student A[100];
	int n,m;
	cout << "sheet2.Q1\n";
	cin >> n;
	for (int i = 0;i < n;i++)
		read(A[i]);
	for (int i = 0; i < m;i++) {
		for (int j = 0; j < m - 1;j++) {
			if (A[i].avg < A[i + 1].avg) {
				student x = A[i];
				A[i] = A[i + 1];
				A[i + 1] = x;
			}
		}
	}
	cout << "Mini : \n"
		<< "Name : " << A[0].name << endl
		<< "Age : " << A[0].age << endl
		<< "Id : " << A[0].Id << endl
		<< "Average : " << A[0].avg << endl
		<< "Max : \n"
		<< "Name : " << A[n].name << endl
		<< "Age : " << A[n].age << endl
		<< "Id : " << A[n].Id << endl
		<< "Average : " << A[n].avg;
}
