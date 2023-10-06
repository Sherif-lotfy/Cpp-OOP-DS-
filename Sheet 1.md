

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
Q2
```
#include <iostream>
using namespace std;
void functionA(int n, int A[]);
void functionB(int n, int A[]);
void functionC(int n, int A[]);
void functionD(int n, int A[]);
void functionE(int n, int A[],int a,int b);
void functionF(int n, int A[]);

int main() {
	int n,A[100];
	cout << "Q2\n"<<"please Enter The Length Of Ur Array\n"<<"N = ";
	cin >> n;
	functionA(n,A);
	return 0;
}
void functionA(int n, int A[]) {
	int a, b;
	for (int i = 0;i < n;i++) {
		cout << "A[" << i + 1 << "]= ";
		cin >> A[i];
	}
	do{
		int x;
		cout << "Which Function do you want to use ?\n"<<"{\n"
			<< "1-b(DisPlay)\n"
			<<"2-c(Search)\n"
			<<"3-d(Replace)\n"
			<<"4-e(Swap)\n"
			<<"5-f(Sort)\n"<<"}";
		cin >> x;
		switch (x)
		{
		case 1: {functionB(n, A);break;}
		case 2: {functionC(n, A);break;}
		case 3: {functionD(n, A);break;}
		case 4:  { {cout << endl << "Choose these two elemem=nt you want to swap...\n"
			<< "First one ...A[?] :";
			cin >> a;
			while (a<0 || a>n) {
				cout << "there is no element with this number ... \n"
					<< "please try again with another number (>0 && <=n) ";
				cin >> a;
			}
			a = a - 1;
			cout << "Second one ...A[?] :";
			cin >> b;
			while (b<0 || b>n) {
				cout << "there is no element with this number ... \n"
					<< "please try again with another number (>0 && <=n) ";
				cin >> b;
			}
			b = b - 1;
			} functionE(n, A, a, b);break;}
		case 5: {functionF(n, A);break;}

		}
	} while (true);
	
}
void functionB(int n, int A[]) {
	for(int i=0; i<n;i++){
		cout << "A[" << i + 1 << "]=" << A[i] << endl;
	}
}
void functionC(int n, int A[]) {
	int N,Search=0;
		cout << "Enter the number you want to search about ...\n" << "N =";
		cin >> N;
		for (int i = 0; i < n; i++) {
			if (A[i] == N) Search = 1;
		}
		if(Search == 0) cout << endl << "This number is not exist\n";
		else cout << endl << "Your number is in the array\n";
}
void functionD(int n, int A[]) {
	int a, b;
	cout << endl << "Enter the number you want to insert \n" << "Number Is :";
	cin >> a;
	cout << "Enter the number of the element that you want to delete... \n" << "A[?] :";
	cin >> b;
	while (b<0 || b>n){
		cout << "this number does not represent any element. please try with another number \n"
			<< "it must be (>0 && <=n)\n"
			<< "A[?] :";
		cin >> b;
	}
	A[b - 1] = a;
	cout << endl << "Done" << endl;
}
void functionE(int n, int A[],int a,int b) {
	int x, y;
	x = A[a];
	y = A[b];
	A[a] = y;
	A[b] = x;
	cout << endl << "Done" << endl;
}
void functionF(int n, int A[]) {
	for (int i = 0;i < n-1;i++) {
		if (A[i] > A[i + 1]) {
			functionE(n, A, i, i + 1);
		}
	}
	for (int i = n-1;i >0;i--) {
		if (A[i] < A[i - 1]) {
			functionE(n, A, i, i - 1);
		}
	}
}
```
