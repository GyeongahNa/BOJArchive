#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int dp[1001];

int main() {
    
    int N;
    scanf("%d", &N);
    
    vector<int> p(N+1);
    for (int i=1; i<=N; i++)
        scanf("%d", &p[i]);
    
    for (int i=1; i<=N; i++) {
        dp[i] = p[i];
        for (int j=1; j<=i-1; j++)
            dp[i] = min(dp[i], dp[j]+p[i-j]);
    }
    printf("%d", dp[N]);
    return 0;
}