#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int N, tmp, sum, cnt;

    cin >> N;
    tmp = N;
    cnt = 0;
    while (true) {
        sum = tmp / 10 + tmp % 10;
        tmp = (tmp % 10) * 10 + (sum % 10);
        cnt++;
        if (tmp == N)
            break;
    }
    printf("%d\n", cnt);
    return 0;
}