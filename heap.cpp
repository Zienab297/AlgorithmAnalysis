#include <iostream>
using namespace std;

int* heapify(int* arr, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;
    if (left < n && arr[i] < arr[left])
        largest = left;
    else
        largest = i;
    if (right < n&& arr[largest] < arr[right])
        largest = right;
    if (largest != i) {
        int temp;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
    return arr;
}

int* sort(int* arr, int n) {
    for (int i = n / 2 - 1; i > -1; i--)
        heapify(arr, n, i);
    int temp;
    for (int i = n - 1; i > 0; i--) {
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0);
    }
    return arr;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    arr = sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}