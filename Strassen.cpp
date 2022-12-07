// the excution time taken for the 30*30 matrix is longer than the excution time taken for the 2*2 marix in question 2
#include<iostream> //complixity is O(n^2)
using namespace std;
int** initializingMatrix(int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}
int** addingmatrix(int** matrixA, int** matrixB, int n) {
	int** matrixC = initializingMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	return matrixC;
}
int** subtractmatrix(int** matrixA, int** matrixB, int n) {
	int** matrixC = initializingMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}
	return matrixC;
}
int** matrixMultiplication(int** matrixA, int** matrixB, int n) {
	if (n == 1) {
		int** C = initializingMatrix(1);
		C[0][0] = matrixA[0][0] * matrixB[0][0];
		return C;
	}
	else
	{
		int s = n / 2;
		int** A11 = initializingMatrix(s);
		int** A12 = initializingMatrix(s);
		int** A21 = initializingMatrix(s);
		int** A22 = initializingMatrix(s);
		int** B11 = initializingMatrix(s);
		int** B12 = initializingMatrix(s);
		int** B21 = initializingMatrix(s);
		int** B22 = initializingMatrix(s);
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				A11[i][j] = matrixA[i][j];
				A12[i][j] = matrixA[i][j + s];
				A21[i][j] = matrixA[i + s][j];
				A22[i][j] = matrixA[i + s][j + s];
				B11[i][j] = matrixB[i][j];
				B12[i][j] = matrixB[i][j + s];
				B21[i][j] = matrixB[i + s][j];
				B22[i][j] = matrixB[i + s][j + s];
			}
		}


		int** matrixC = initializingMatrix(n);
		int** P1 = matrixMultiplication(subtractmatrix(A11, A21, s), addingmatrix(B11, B12, s), s);
		int** P2 = matrixMultiplication(addingmatrix(A11, A22, s), addingmatrix(B11, B22, s), s);
		int** P3 = matrixMultiplication(subtractmatrix(A12, A22, s), addingmatrix(B21, B22, s), s);
		int** P4 = matrixMultiplication(A11, subtractmatrix(B12, B22, s), s);
		int** P5 = matrixMultiplication(A22, subtractmatrix(B21, B11, s), s);
		int** P6 = matrixMultiplication(addingmatrix(A21, A22, s), B11, s);
		int** P7 = matrixMultiplication(addingmatrix(A11, A12, s), B22, s);

		int** C11 = addingmatrix(addingmatrix(P3, P2, s), subtractmatrix(P5, P7, s), s);
		int** C12 = addingmatrix(P4, P7, s);
		int** C21 = addingmatrix(P5, P6, s);
		int** C22 = addingmatrix(subtractmatrix(P2, P1, s), subtractmatrix(P4, P6, s), s);

		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++) {
				matrixC[i][j] = C11[i][j];
				matrixC[i][j + s] = C12[i][j];
				matrixC[s + i][j] = C21[i][j];
				matrixC[s + i][s + j] = C22[i][j];
			}
		return matrixC;
	}
}
int main() {
	int n;
	cin >> n;
	int** matrix1 = initializingMatrix(n);
	int** matrix2 = initializingMatrix(n);
	cout << "Enter the first array\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix1[i][j];
		}
	}
	cout << "Enter the second array\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix2[i][j];
		}
	}
	int** result= initializingMatrix(n);
	result= matrixMultiplication(matrix1, matrix2, n);
	cout << "The answer is: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout <<" " << result[i][j];
		}
		cout<<"\n";
	}
	return 0;
}