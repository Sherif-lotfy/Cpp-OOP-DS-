#include <iostream>
using namespace std;
class matrix {
	double M[10][10];
	int n, m;
public:
	matrix() {
		n = m = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				M[i][j] = 0;
		}
	}
	bool prime(double z) {
		if (z < 2) return false;
		for (int i = 2; i < z; i++) {
			if ((int)z % i == 0)return false;
		}
		return true;
	}
	void read() {
		cout << "No. of rows is : ";
		cin >> m;
		cout << "No. of columns is : ";
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				cout << "M[" << j + 1 << "][" << i + 1 << "] = ";
				cin >> M[j][i];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (M[i][j] > 0 && prime(M[i][j]))
					M[i][n - 1] += M[i][j];
			}
		}
	}
	void display() {
		cout << endl;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++)
				cout << "M[" << j + 1 << "][" << i + 1 << "] = " << M[j][i] << endl;
		}
		cout << endl;
	}
	double operator [] (int q) { return M[q][n - 1]; }
	friend matrix operator *(int constant , matrix X);
	bool operator >= (matrix A) {
		int z = m;
		if (z > A.m) z = A.m;
		for (int i = 0; i < z; i++) {
			if (M[i][n - 1] < A[i])
				return false;
		}
		return true;
	}
	matrix operator *(matrix A) {
		matrix B;
		if (n != A.m) {
			cout << "Multiplication can not be applied\n";
			B.m = m;
			B.n = n;
			return B;
		}
		B.m = m;
		B.n = A.n;
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				for (int k = 0; k < n; k++)
					B.M[j][i] += M[j][k] * A.M[k][i];
			}
		}
		return B;
	}
	int NoOfRows() { return m; }
};
	matrix operator *( int constant , matrix X) {
		matrix Zz;
		Zz.m = X.m;
		Zz.n = X.n;
		for (int i = 0; i < X.n; i++) {
			for (int j = 0; j < X.m; j++) {
				Zz.M[j][i] =constant *  X.M[j][i];
			}
		}
		return Zz;
	}
void main() {
	matrix X,Y,Z,C;
	X.read();
	Y.read();
	if (X >= Y) {
		X.display();
		Z = 5 * Y;
		cout << "Z = 5 * Y\n";
		for (int i = 0; i < Z.NoOfRows(); i++) {
			cout << "Z[" << i + 1 << "] = " << Z[i]<<endl;
		}
	}
	else {
		Y.display();
		Z = 2 * X;
		cout << "Z = 2 * X\n";
		for (int i = 0; i < Z.NoOfRows(); i++) {
			cout << "Z[" << i + 1 << "] = " << Z[i]<<endl;
		}
	}
	C = X * Y;
	C.display();
	for (int i = 0; i < C.NoOfRows(); i++) {
		cout << "C[" << i + 1 << "] = " << C[i] << endl;
	}
}