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
#include <iostream>

#define mod 1000000007

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N;
int dp[200005][2][5];

vector<int> bf[5] = {{}, {3, 4}, {4}, {1}, {1, 2}};

void dynamic() {

    dp[1][0][0] = 1;
    for (int k=1; k<=4; k++) {
        dp[1][1][k] = 1;
    }

    for (int i=2; i<=200000; i++) {
    
        //dp[i][0][0]
        for (int k=1; k<=4; k++) {
            dp[i][0][0] = (dp[i][0][0]+dp[i-1][1][k])%mod;
        }

        //dp[i][1][k]
        for (int k=1; k<=4; k++) {
            dp[i][1][k] = (dp[i][1][k]+dp[i-1][0][0])%mod;
            for (auto x : bf[k]) {
                dp[i][1][k] = (dp[i][1][k]+dp[i-1][1][x])%mod;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    dynamic();

    cin >> N;
    int ans = dp[N][0][0];
    for (int k=1; k<=4; k++) {
        ans = (ans+dp[N][1][k])%mod;
    }
    cout << ans;
    return 0;
}