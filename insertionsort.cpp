//a recrusive insertion sort technique
//the worst case is when the array is sorted backwards
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    if (n >= 1) {
        insertionSort(arr, n - 1); //using recrusion instead of a for loop
        int temp = arr[n - 1];
        int counter = n - 2;
        while (counter >= 0 && arr[counter] > temp) { //comparing the elements in the end with all elements infornt of it
            arr[counter + 1] = arr[counter];
            counter--;
        }
        arr[counter + 1] = temp;
    }
    else return;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    //entering the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
    //printing the sorted array
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
}