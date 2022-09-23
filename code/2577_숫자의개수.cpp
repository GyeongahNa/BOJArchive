#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {

    int A, B, C, cnt;
    const char* mul;

    cin >> A >> B >> C;
    mul = to_string(A * B * C).c_str();
    for (int i = 0; i < 10; i++) {
        cnt = count(mul, mul + strlen(mul), i + 48);
        printf("%d\n", cnt);
    }

    return 0;
}