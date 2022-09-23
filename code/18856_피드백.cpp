#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

bool isPrime(int N) {

    if (N == 1) return false;
    for (int i=2; i*i<=N; i++)
        if (N%i == 0) return false;
    return true;
}

int main() {

    int N;
    scanf("%d", &N);
    printf("%d\n", N);
    for (int i=1; i<=N-1; i++) printf("%d ", i);
    while (!isPrime(N)) N++;
    printf("%d", N);
    return 0;
}