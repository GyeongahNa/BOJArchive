#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    double a, b;

    cin >> a >> b;
    cout << int(24 * abs(a / b - 1) / 12) << endl;
    return 0;
}