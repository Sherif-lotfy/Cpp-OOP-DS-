#include <iostream>
#include <string>
using namespace std;
class student {
protected:
	string name;
	float age;
	int id;
public:
	student() { age = 0; id = 0; }
	void read() {
		cout << "Name is : ";
		cin >> name;
		cout << "Age is : ";
		cin >> age;
		cout << "ID is : ";
		cin >> id;
	}
	void write() {
		cout << "Name is : " << name << endl
			<< "Age is : " << age << endl
			<< "ID is : " << id << endl;
	}
};
class math :virtual public student {
protected:
	string mc[3];
	double D[3], sum;
public:
	math() { D[0] = D[1] = D[2] = sum = 0; }
	void read() {
		for (int i = 0; i < 3; i++) {
			cout << "MC[" << i + 1 << "] is : ";
			cin >> mc[i];
			cout << "D[" << i + 1 << "](%) is : ";
			cin >> D[i];
			sum += D[i];
		}
	}
	void write() {
		for (int i = 0; i < 3; i++) {
			cout << "MC[" << i + 1 << "] is : " << mc[i] << endl
				<< "D[" << i + 1 << "](%) is : " << D[i] << endl;
		}
		cout<< "Sum is : " << sum << endl;
	}
};
class cs :virtual public student {
protected:
	string csc[5];
	double D[5], sum;
public:
	cs() { D[0] = D[1] = D[2] = D[3] = D[4] = sum = 0; }
	void read() {
		for (int i = 0; i < 5; i++) {
			cout << "CSC[" << i + 1 << "] is : ";
			cin >> csc[i];
			cout << "D[" << i + 1 << "](%) is : ";
			cin >> D[i];
			sum += D[i];
		}
	}
	void write() {
		for (int i = 0; i < 5; i++) {
			cout << "CSC[" << i + 1 << "] is : " << csc[i] << endl
				<< "D[" << i + 1 << "](%) is : " << D[i] << endl;	
		}
		cout<< "Sum is : " << sum << endl;
	}
};
class result : public math, public cs {
	double total;
	char gpa[2];
public:
	result() { total = 0; gpa[0] = gpa[1] = ' '; }
	void read() {
		total = math::sum + cs::sum;
		//total = sum of 8 subjectes.
		total /= 8;
		//total /= 8 <- Average .
		(total >= 90) ? gpa[0] = 'A', gpa[1] = ' ' :
			(90 > total && total >= 85) ? gpa[0] = 'B', gpa[1] = '+' :
			(85 > total && total >= 80) ? gpa[0] = 'B', gpa[1] = ' ' :
			(80 > total && total >= 70) ? gpa[0] = 'C', gpa[1] = '+' :
			(70 > total && total >= 65) ? gpa[0] = 'C', gpa[1] = ' ' :
			(65 > total && total >= 60) ? gpa[0] = 'D', gpa[1] = ' ' :
			(60 > total) ? gpa[0] = 'F', gpa[1] = ' ' : 0;
	}
	void write() {
		cout << "Total (Average) is : " << total << endl
			<< "GPA is : " << gpa[0]<<gpa[1];
	}
};
void main() {
	result x;
	x.student::read();
	x.math::read();
	x.cs::read();
	x.read();
	x.student::write();
	x.math::write();
	x.cs::write();
	x.write();
}
