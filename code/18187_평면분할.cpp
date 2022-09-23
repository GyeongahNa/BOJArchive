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

int dp[101];

int main() {

    int N;
    scanf("%d", &N);
    memset(dp, 0, sizeof(dp));

    dp[1] = 2;
    for (int i=2; i<=N; i++)
        dp[i] = dp[i-1] + (i - (i-1)/3);
    printf("%d", dp[N]);
    return 0;
}
