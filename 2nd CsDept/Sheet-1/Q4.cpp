#include <iostream>
#include <math.h>
using namespace std;
void reverse (int a){
	int count=0 ,power,sum=0;
	for (int i = 1;i <= a; i *= 10) {
		count++;
	}
	power = count - 1;
	for (int i = 0;i <= count;i++) {
		sum += (a % 10) * pow(10, power);
		a /= 10;
		power--;
	}
	cout <<"Number After revrse :"<< sum << endl;
}
int main() {
	int Number;
	cout << "Q1.e\n"<<"Enter The Number You Want To Reverse\n"<<"Number Is :";
	cin >> Number;
	reverse(Number);
	system("pause");
	return 0;
}
