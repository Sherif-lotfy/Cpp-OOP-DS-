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
