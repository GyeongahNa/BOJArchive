#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int a[1000];
int d[1000];
int v[1000];

// 역추적 개념 공부 후 풀이
void go(int idx) {

    if (idx == -1) return ;
    go(v[idx]);
    printf("%d ", a[idx]);
}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++)
        scanf("%d", &a[i]);

    for (int i=0; i<N; i++) {
        d[i] = 1;
        v[i] = -1;
        for (int j=0; j<i; j++) {
            if (a[j] >= a[i]) continue;
            if (d[i] >= d[j]+1) continue;
            d[i] = d[j]+1;
            v[i] = j;
        }
    }

    int maxd = 0, maxidx = 0;
    for (int i=0; i<N; i++) {
        if (d[i] > maxd) {
            maxd = d[i];
            maxidx = i;
        }
    }

    printf("%d\n", maxd);
    go(maxidx);
    return 0;
}

// "역추적" 개념 모를 때 풀이
// int N;
// int dp[1000];
// vector<vector<int>> seq(1000);

// int main() {
    
//     scanf("%d", &N);
//     memset(dp, 0, sizeof(dp));
    
//     vector<int> v(N);
//     for (int i=0; i<N; i++)
//         scanf("%d", &v[i]);
    
//     dp[0] = 1;
//     seq[0].push_back(v[0]);
    
//     for (int i=1; i<N; i++) {
//         for (int j=0; j<i; j++) {
//             if (v[j] >= v[i]) continue;
//             if (dp[i] >= dp[j]) continue;
//             dp[i] = dp[j];
//             seq[i] = seq[j];
//         }
//         dp[i]++;
//         seq[i].push_back(v[i]);
//     }
    
//     int idx = max_element(dp, dp+N)-dp;
//     printf("%d\n", dp[idx]);
//     for (int i=0; i<seq[idx].size(); i++)
//         printf("%d ", seq[idx][i]);
//     return 0;
// }