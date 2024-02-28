#include <iostream>
using namespace std;
void counter (int a){
	int count=0;
	for (int i = 1;i <= a; i *= 10) {
		count++;
	}
	cout <<"Number Of Digits Is :"<< count << endl;
}
int main() {
	int Number;
	cout << "Q1.e\n"<<"Enter The Number You Want To Count Its Digits\n"<<"Number Is :";
	cin >> Number;
	counter(Number);
	system("pause");
	return 0;
}
