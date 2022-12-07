//complixity is O(n^3)
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int matrixA[n][n], matrixB[n][n], matrixC[n][n];
	cout << "Enter matrix number 1. \n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrixA[i][j];
		}
	}
	cout << "Enter matrix number 2. \n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrixB[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixC[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	cout << "The answer is..\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrixC[i][j] << "  ";
		}
		cout << "\n";
	}
}