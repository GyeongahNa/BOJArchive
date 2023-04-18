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

int N, M;
int A[105];
int dp[105][55];
int pfx[105];

void getInput() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        pfx[i] = pfx[i-1]+A[i];
    }
}

void dynamic() {

    for (int i=0; i<=N; i++) {
        for (int j=0; j<=M; j++)
            dp[i][j] = -1e9;
    }

    for (int i=1; i<=N; i++) {
        int mx = dp[i-1][1];
        for (int j=1; j<=i; j++) {
            mx = max(mx, pfx[i]-pfx[j-1]);
        }
        dp[i][1] = mx;
    }

    for (int i=1; i<=N; i++) {
        for (int j=2; j<=M; j++) {
            int mx =  dp[i-1][j];
            for (int k=i; k>=1; k--) {
                int last = pfx[i]-pfx[k-1];
                for (int l=k-2; l>=1; l--) {
                    mx = max(mx, dp[l][j-1]+last);
                }
            }
            dp[i][j] = mx;
        }
    }
}

int main() {

    getInput();
    dynamic();

    int ans = -1e9;
    for (int i=1; i<=N; i++) {
        ans = max(ans, dp[i][M]);
    }
    cout << ans;
    return 0;
}