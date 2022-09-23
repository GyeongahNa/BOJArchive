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

int N;
int A[1001];
int dp[1001];

int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &A[i]);
    
    dp[0] = 1;
    int dpMax = 1;
    for (int i=1; i<N; i++) {
        int max=0;
        for (int j=0; j<i; j++) {
            if (A[j] >= A[i]) continue;
            if (max < dp[j]) max = dp[j];
        }
        dp[i] = max+1;
        if (dp[i] > dpMax) dpMax = dp[i];
    }
    printf("%d", dpMax);
    return 0;
}