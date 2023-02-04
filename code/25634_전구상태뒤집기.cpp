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

int N;
int a[200005];
int b[200005];
int dp[200005][2][2];

int opp(int x) {
    return x ? 0 : 1;
}

int main() {

    cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=N; i++) cin >> b[i];

    dp[1][1][0] = a[1]*opp(b[1]);
    dp[1][0][0] = a[1]*b[1];

    dp[2][0][0] = a[1]*b[1] + a[2]*b[2];
    dp[2][0][1] = a[1]*opp(b[1]) + a[2]*b[2];
    dp[2][1][0] = a[1]*b[1] + a[2]*opp(b[2]);
    dp[2][1][1] = a[1]*opp(b[1]) + a[2]*opp(b[2]);

    for (int i=3; i<=N; i++) {
        dp[i][1][0] = dp[i-1][0][0] + a[i]*opp(b[i]);
        dp[i][1][1] = max(dp[i-1][1][0], dp[i-1][1][1])+a[i]*opp(b[i]);
        dp[i][0][0] = dp[i-1][0][0] + a[i]*b[i];
        dp[i][0][1] = max({dp[i-1][0][1], dp[i-1][1][0], dp[i-1][1][1]})+a[i]*b[i];
    }

    int re = max({dp[N][1][0], dp[N][1][1], dp[N][0][1]});
    cout << re;
    return 0;
}