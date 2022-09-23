#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {

    long long A, B, C, D;
    string n1, n2;

    cin >> A >> B >> C >> D;
    n1 = to_string(A) + to_string(B);
    n2 = to_string(C) + to_string(D);
    cout << stoll(n1) + stoll(n2) << endl;

    return 0;
}