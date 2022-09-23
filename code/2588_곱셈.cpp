#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string n1, n2;
    int re, sum;

    cin >> n1 >> n2;
    sum = 0;
    for (int i = 2; i >= 0; i--) {
        re = stoi(n1) * (n2[i] - 48);
        cout << re << endl;
        sum += re * pow(10, 2 - i);
    }

    cout << sum << endl;
    return 0;
}