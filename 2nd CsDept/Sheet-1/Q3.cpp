#include <iostream>
using namespace std;
void Test(float a) {
	int PrimeTest =1;
	for (int i = a-1; i > 1; i--) {
		if ((int)a % i == 0) {
			PrimeTest = i;
		}
	}
	if (PrimeTest != 1) cout << "The Float Number Is Not A Prime Number.\n";
	else cout << "The Float Number Is A Prime Number.\n";
}
int main() {
	float Number;
	cout << "Q1.c\n" << "enter The Number You Want To Test\n" << endl << "Num is :";
	cin >> Number;
	Test(Number);
	system("pause");
	return 0;
}
