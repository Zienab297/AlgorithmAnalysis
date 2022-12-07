#include <iostream>
using namespace std;

int getMax(string arr[], int n) {
    int max = arr[0].length();
    for (int i = 0; i < n; i++) {
        if (max < arr[i].length()) {
            max = arr[i].length();
        }
    }
}

void countSort(string arr[], int n, int k) {
    string b[16];
    int c[100];

    for (int i = 0; i < 100; i++) {
        c[i] = 0;
    }
    for (int j = 0; j < n; j++) {
        c[k < arr[j].size() ? (int)(unsigned char)arr[j][k] + 1 : 0]++;
    }

    for (int i = 1; i < 100; i++) {
        c[i] += c[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        b[c[k < arr[j].size() ? (int)(char)arr[j][k] + 1 : 0] - 1] = arr[j];
        c[k < arr[j].size() ? (int)(char)arr[j][k] + 1 : 0]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = b[i];
    }

}

void radixSort(string arr[], int n) {
    int max = getMax(arr, n);
    for (int digit = max; digit > 0; digit--) {
        countSort(arr, n, digit - 1);
    }
}

int main()
{
    string arr[16] = { "COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX" };
    int n = 16;

    radixSort(arr, n);

    for (size_t i = 0; i < n; i++) {
        cout << "\n" << arr[i];
    }
    return 0;
}