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

int gcd(int a, int b) {
    
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    N = max(N, -N);
    M = max(M, -M);
    if (N == 0 && M == 0) printf("0");
    else if (gcd(max(N, M), min(N, M)) == 1) printf("1");
    else printf("2");
    return 0;
}