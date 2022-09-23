#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int dp[100001][4];

int main() {

    memset(dp, 0, sizeof(dp));
    
    dp[1][1] = 1; 
    dp[2][2] = 1; 
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1; 

    for (int i=4; i<=100000; i++) {    
        dp[i][1] = (dp[i-1][2]+dp[i-1][3])%1000000009;
        dp[i][2] = (dp[i-2][1]+dp[i-2][3])%1000000009;
        dp[i][3] = (dp[i-3][1]+dp[i-3][2])%1000000009;
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", ((dp[n][1]+dp[n][2])%1000000009+dp[n][3])%1000000009);
    }
    
    return 0;
}