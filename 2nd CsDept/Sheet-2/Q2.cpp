#include <iostream>
using namespace std;
struct TTax {
	float price;
	float tax;
};
struct Toy {
	string Tname;
	TTax Tprice;
	float NetPrice;
};
void read(Toy& X) {
	cout << "TName is : ";
	cin >> X.Tname;
	cout << "price is : ";
	cin >> X.Tprice.price;
	cout << "tax (%) is : ";
	cin >> X.Tprice.tax;
	cout << endl;
	X.NetPrice = X.Tprice.price / (1 + (X.Tprice.tax / 100));
}
void display(Toy X) {
	cout << endl
		<< "TName : " << X.Tname << endl
		<< "Price : " << X.Tprice.price << " & tax : " << X.Tprice.tax << "%" << endl
		<< "Net_price : " << X.NetPrice << endl;
}
void main() {
	Toy A[100];
	int n;
	cout << "sheet2.Q2\n"
		<< "lenght of your array : ";
	cin >> n;
	for (int i = 0; i < n; i++)
		read(A[i]);
	for (int i = 0; i < n; i++) {
		if (A[i].NetPrice > 50)
			display(A[i]);
	}
}