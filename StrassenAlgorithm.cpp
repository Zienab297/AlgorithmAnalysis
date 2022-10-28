//complixity is O(n^3)
#include<iostream>
using namespace std;
int** initializingMatrix(int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	return matrix;
}

int** addingmatrix(int** matrixA, int** matrixB) {
	int n = sizeof matrixA / sizeof matrixA;
	int s = n / 2;
	int** matrixC = initializingMatrix(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	return matrixC;
}


int** matrixMultiplication(int** matrixA, int** matrixB, int n) {
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
	if (n == 1) {
		int** matrixC = initializingMatrix(1);
		matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
	}
	else {
		int** matrixC = initializingMatrix(n);
		int** C11 = addingmatrix(matrixMultiplication(A11, B11, n / 2), matrixMultiplication(A12, B21, n / 2));
		int** C12 = addingmatrix(matrixMultiplication(A11, B12, n / 2), matrixMultiplication(A12, B22, n / 2));
		int** C21 = addingmatrix(matrixMultiplication(A21, B11, n / 2), matrixMultiplication(A22, A21, n / 2));
		int** C22 = addingmatrix(matrixMultiplication(A21, B12, n / 2), matrixMultiplication(A22, B22, n / 2));

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
	int** matrix1 = initializingMatrix(n);
	int** matrix2 = initializingMatrix(n);
	cout << "Enter the first array";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix1[i][j];
		}
	}
	cout << "Enter the second array";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix2[i][j];
		}
	}
	int** result = matrixMultiplication(matrix1, matrix2, n);
}