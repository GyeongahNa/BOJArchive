#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int C, N;
ii city[25]; //(비용, 고객수)
int dp[100005];

void getInput() {

    cin >> C >> N;
    for (int i=1; i<=N; i++) {
        cin >> city[i].X >> city[i].Y;
    }
}

int main() {

    getInput();

    int ans = 1e9;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=100000; j++) {
            if (j-city[i].X < 0) continue;
            dp[j] = max(dp[j], dp[j-city[i].X]+city[i].Y);
            if (dp[j] >= C) ans = min(ans, j);
        }
    }

    cout << ans;
    return 0;
}