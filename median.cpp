//running time of O(n)
#include<iostream>
using namespace std;

float median(int array1[], int array2[], int n, int m) {
	float median1, median2, median;
	int middle1 = n / 2;
	int middle2 = m / 2;
	if (n % 2 == 0) {
		median1 = (array1[middle1] + array1[middle1 + 1]) / 2;
	}
	else if (n % 2 == 1) {
		median1 = array1[middle1];
	}

	if (m % 2 == 0) {
		median2 = (array2[middle2] + array2[middle2 + 1]) / 2;
	}
	else if (m % 2 == 1) {
		median2 = array2[middle2];
	}
	median = (median1 + median2) / 2;
	return median;
}
int main() {
	int n, m;
	cout << "Enter the size of the first array: \n";
	cin >> n;
	int array1[n];

	cout << "Enter the first array: \n";
	for (int i = 0; i < n; i++) {
		cin >> array1[i];
	}
	cout << "Enter the size of the second array: \n";
	cin >> m;
	int array2[m];
	cout << "Enter the second array: \n";
	for (int i = 0; i < m; i++) {
		cin >> array2[i];
	}
	cout << median(array1, array2, n, m);
}