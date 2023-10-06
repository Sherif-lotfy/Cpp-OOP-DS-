

####Q1)
Q1.a
```
#include <iostream>
using namespace std;
void Test (int a , int b){
	if (a % b == 0) { cout << "integer 1 is divisible by integer 2 \n"; }
	else if (b % a == 0) { cout << "integer 2 is divisible by integer 1 \n"; }
	else { cout << "integer 1 & integer 2 are not divisible by each other \n"; }
}
int main() {
	int integer1, integer2;
	cout << "Herzlich Willkommen" << endl << "please enter the first integer " << endl << "integer 1 :";
	cin >> integer1;
	cout << "please enter the second integer " << endl << "integer2 :";
	cin >> integer2;
	cout << endl;
	Test(integer1, integer2);
	system("pause");
	return 0;
}
```
Q1.b
```
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
```
Q1.c
```
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
```
Q1.d
```
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
```
Q1.e
```
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
```
---
