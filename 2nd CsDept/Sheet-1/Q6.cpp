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
			} functionE(n, A, a, b);cout << endl << "Done" << endl;break;}
		case 5: {functionF(n, A);cout << endl << "Done" << endl;break;}

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
	int x;
	x = A[a];
	A[a] = A[b];
	A[b] = x;
}
void functionF(int n, int A[]) {
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - 1;j++) {
			if (A[j] > A[j + 1]) functionE(n, A, j, j + 1);
		}
	}
}
