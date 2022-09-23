#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    long long N, sum;

    cin >> N;
    sum  = 0;
    for (long i = 1; i < N; i++) {
        sum += i * N + i;
    }
    printf("%lld\n", sum);
    return 0;
}