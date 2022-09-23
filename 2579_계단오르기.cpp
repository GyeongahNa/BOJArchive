#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int dp[301];

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N+1);
    for (int i=1; i<=N; i++)
        scanf("%d", &v[i]);

    dp[0] = 0; dp[1] = v[1]; dp[2] = v[1]+v[2];
    for (int i=3; i<=N; i++)
        dp[i] = v[i] + max(dp[i-2], v[i-1]+dp[i-3]);
    printf("%d", dp[N]);
    return 0;
}