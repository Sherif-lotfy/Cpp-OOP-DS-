#include <iostream>
using namespace std;
void fuctionA(int n, int A[]);
void fuctionB(int n, int A[]);
void fuctionC(int n, int A[]);
void fuctionD(int n, int A[]);
void fuctionE(int n, int A[]);

int main() {
	int n, A[100];
	cout << "Q3\n"<<"Enter the length of your array ...\n"<<"N =";
	cin >> n;
	cout << endl;
	fuctionA(n, A);
	return 0;
}
void fuctionA(int n, int A[]) {
	int x;
	for (int i = 0; i < n;i++) {
		cout << "A[" << i + 1 << "] = ";
		cin >> A[i];
	}
	do {
		cout << "which function do want to use ??\n"
			<< "1-b(Dispaly)\n"
			<< "2-c(reverse)\n"
			<< "3-d(return the occurrence for every number)\n"
			<< "4- e (Summation)" << endl;
		cin >> x;
		switch (x) {
		case 1: {fuctionB(n, A);break;}
		case 2: {fuctionC(n, A);break;}
		case 3: {fuctionD(n, A);break;}
		case 4: {fuctionE(n, A);break;}
		}
	}while (true);
	cout << endl;
}
void fuctionB(int n, int A[]) {
	cout << endl;
	for (int i = 0;i < n;i++) {
		cout << "A[" << i + 1 << "]=" << A[i] << endl;
	}
}
void fuctionC(int n, int A[]) {
	int j = n - 1,B[100];
	for (int i = 0; i < n; i++) {
		B[j] = A[i];
		j--;
	}
	for (int i = 0; i < n;i++) {
		A[i] = B[i];
	}
	cout << endl << "Done\n";
}
void fuctionD(int n, int A[]) {
	int B[100], counter = 0, m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m+1; j++) {
			if (m != 0) {
				if (A[i] == B[j]) counter = 1;
			}
		}
		if (counter != 0) continue;
		for (int j = 0; j < n;j++) {
			if (i == j) continue;
			if (A[i] == A[j]) counter++;
		}
		if (counter != 0) {
			cout << "Number " << A[i] << " occurrs " << counter+1 << " times \n";
			B[m] = A[i];
			m++;
		}
		counter = 0;
	}
}
void fuctionE(int n, int A[]) {
	int B[100],sum =0;
	for (int i = 0; i < n;i++) {
		for (int j = 0;j <= i;j++) {
			sum += A[j];
		}
		B[i] = sum;
		sum = 0;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "B[" << i + 1 << "] = " << B[i] << endl;
	}
}
