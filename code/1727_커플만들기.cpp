#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int n, m;
int men[1005];
int women[1005];
int dp[1005][1005];

void getInput() {

    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        cin >> men[i];
    }

    for (int i=1; i<=m; i++) {
        cin >> women[i];
    }

    sort(men+1, men+n+1);
    sort(women+1, women+m+1);
}

int main() {

    getInput();

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i == j) {
                dp[i][j] = dp[i-1][j-1] + abs(men[i]-women[j]);
            }
            else if (i > j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + abs(men[i]-women[j]));
            }
            else {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+abs(men[i]-women[j]));
            }
        }
    }

    cout << dp[n][m];
    return 0;
}