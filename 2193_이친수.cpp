#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

long long dp[91];

int main() {

    int N;
    scanf("%d", &N);

    dp[1] = 1; 
    dp[2] = 1;
    for (int i = 3; i<= N; i++)
        dp[i] = dp[i-1]+dp[i-2];
    printf("%lld", dp[N]);
    return 0;
}

// 시간초과 + count 범위 오버플로우
// void solve(int idx, int N, string s, int& count) {

//     if (idx == N) {
//         if (s[0] == '0') return ;
//         for (int i=0; i<(int)s.size()-1; i++)
//             if (s[i] == '1' && s[i+1] == '1') return ;
//         count++;
//         return;
//     }
//     solve(idx+1, N, s+"0", count);
//     solve(idx+1, N, s+"1", count);
// }

// int main() {

//     int N;
//     scanf("%d", &N);

//     int count = 0;
//     solve(0, N, "", count);
//     printf("%d", count);
//     return 0;
// }