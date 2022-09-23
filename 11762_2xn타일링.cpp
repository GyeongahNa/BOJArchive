#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

long long dp[1001];

int main() {

    int N;
    scanf("%d", &N);

    dp[1] = 1; dp[2] = 2;
    for (int i=3; i<=N; i++)
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    printf("%lld\n", dp[N]);
    return 0;
}