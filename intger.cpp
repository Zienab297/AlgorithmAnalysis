#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long multiply(long x, long y) {
    if (x < 10 || y < 10) //base case
        return x * y;
    else {
        int len_x = to_string(x).length();
        int len_y = to_string(y).length();
        int n = max(len_x, len_y);
        int m = n / 2;

        long a = x / (long)pow(10, m);
        long b = x % (long)pow(10, m);
        long c = y / (long)pow(10, m);
        long d = y % (long)pow(10, m);

        long ac = multiply(a, c);
        long bd = multiply(b, d);
        long middle = multiply(a + b, c + d);

        long result = ac * (long)pow(10, 2 * m) + (middle * (long)pow(10, m)) + bd - ((ac + bd) * pow(10, m));

        return result;
    }
}

int main() {
    long x, y;
    cin >> x;
    cin >> y;
    long z = multiply(x, y);
    cout << z;
}