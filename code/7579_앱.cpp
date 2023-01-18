#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
int m[105], c[105];
int dp[10005][105];

void getInput() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> m[i];
    for (int i=1; i<=N; i++) cin >> c[i];
}

int main() {

    getInput();

    for (int j=1; j<=N; j++) {
        for (int i=0; i<=10000; i++) {
            dp[i][j] = dp[i][j-1];
            if (i >= c[j]) dp[i][j] = max(dp[i][j], dp[i-c[j]][j-1] + m[j]);
        }
    }

    for (int i=0; i<=10000; i++) {
        if (dp[i][N] < M) continue;
        cout << i;
        return 0;
    }

    return 0;
}