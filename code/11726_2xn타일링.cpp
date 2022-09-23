#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int dp[1001];

int main() {
    
    int N;
    scanf("%d", &N);
    
    dp[1] = 1; dp[2] = 2;
    for (int i=3; i<=N; i++)
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    printf("%d", dp[N]);
    return 0;
}