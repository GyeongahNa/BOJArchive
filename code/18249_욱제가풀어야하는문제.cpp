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

int T, N;
int dp[200005];

void dynamic() {

    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=200000; i++) {
        dp[i] = (dp[i-2]+dp[i-1])%(1000000007);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    dynamic();
    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
     }
     return 0;
}