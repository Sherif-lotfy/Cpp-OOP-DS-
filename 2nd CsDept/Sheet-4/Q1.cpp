#include <iostream>
using namespace std;
class product {
private:
	string name;
	float price, tax;
	int serial;
	static int pserial;
public:
	product() {
		pserial -= 10;
		serial = pserial;
	}
	void read() {
		cout << "name of this product ? : ";
		cin >> name;
		cout << endl << "price ? : ";
		cin >> price;
		cout << endl << "tax (%) :";
		cin >> tax;
		cout << endl;
	}
	void display() {
		float net_price;
		net_price = price / (1 + tax);
		cout << "name is : " << name << endl
			<< "net_price is :" << net_price << endl
			<< "serial is : " << serial << endl;
	}
	void displayPserial() { cout << "pserial is : " << pserial; }
};
int product::pserial = 10000;
void main() {
	cout<<"Q1\n";
	product x, y, z;
	x.read();
	y.read();
	z.read();
	cout << endl;
	x.display();
	y.display();
	z.display();
	cout << endl;
	x.displayPserial();
}
