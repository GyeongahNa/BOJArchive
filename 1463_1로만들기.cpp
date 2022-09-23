#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int dp[1000001];

int solve(int n) {

    if (dp[n] != -1) return dp[n];
    if (n == 1) return dp[1] = 0;
    if (n%2 == 0 && n%3 == 0)
        return dp[n] = min({solve(n/2), solve(n/3), solve(n-1)})+1;
    if (n%2 == 0)
        return dp[n] = min(solve(n/2), solve(n-1))+1;
    if (n%3 == 0)
        return dp[n] = min(solve(n/3), solve(n-1))+1;
    return dp[n] = solve(n-1)+1;
}

int main() {

    int N;
    scanf("%d", &N);
    memset(dp, -1, sizeof(int)*1000001);
    printf("%d", solve(N));
    return 0;
}