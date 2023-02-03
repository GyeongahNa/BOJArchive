#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int cost[1005][3];
int dp[1005][3][3];

void getInput() {

    cin >> N;
    for (int i=0; i<1005; i++) {
        for (int j=0; j<3; j++)
            for (int k=0; k<3; k++)
                dp[i][j][k] = 1e9;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++)
            cin >> cost[i][j];
    }
}

int main() {

    getInput();

    dp[0][0][0] = cost[0][0];
    dp[0][1][1] = cost[0][1];
    dp[0][2][2] = cost[0][2];

    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                for (int c=0; c<3; c++) {
                    if (j == c) continue;
                    if (i == N-1 && k == j) continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][c][k]+cost[i][j]);
                }
            }
        }
    }

    int re = 1e9;
    for (int j=0; j<3; j++) {
        for (int k=0; k<3; k++)
            re = min(re, dp[N-1][j][k]);
    }
    cout << re;
    return 0;
}