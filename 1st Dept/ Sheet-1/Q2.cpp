#include <iostream>
using namespace std;
void Test(int a, int b) {
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	int c = a, gcf = 1;
	if (b < a) c = b;
	for (int i = 1; i <= c; i++) {
		if (a % i == 0 && b % i == 0) gcf = i;
	}
	cout << "integer1 is :" << a << endl << "integer2 is :" << b << endl
		<< "The Greatest Comman Factor is : " << gcf << endl;
}
int main() {
	int integer1, integer2;
	cout << "Q1.b\n" << "please enter the first integer\n" << "integer1 is :";
	cin >> integer1;
	cout << endl << "please enter the second integer\n" << "integer2 is :";
	cin >> integer2;
	cout << endl << endl;
	Test(integer1, integer2);
	system("pause");
	return 0;
}
