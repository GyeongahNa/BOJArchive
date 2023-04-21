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

int T, n, m;
long long dp[15][2005];

int main() {

    for (int i=1; i<=10; i++) {
        for (int j=1; j<=2000; j++) {
            if (i == 1) {
                dp[i][j] = 1;
                continue;
            }
            long long cnt = 0;
            for (int k=1; k<=j/2; k++) {
                cnt += dp[i-1][k];
            }
            dp[i][j] = cnt;
        }
    }

    cin >> T;
    while (T--) {
        cin >> n >> m;
        long long ans = 0;
        for (int i=1; i<=m; i++) {
            ans += dp[n][i];
        }
        cout << ans << '\n';
    }
    return 0;
}