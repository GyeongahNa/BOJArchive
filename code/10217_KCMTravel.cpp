#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
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

int T, N, M, K, u, v, c, d;
vector<vector<iii>> graph(105);
int memo[105][10005];

void getInput() {

    cin >> N >> M >> K;
    for (int i=0; i<105; i++) {
        graph[i].clear();
        for (int j=0; j<10005; j++)
            memo[i][j] = -1;
    }

    for (int i=0; i<K; i++) {
        cin >> u >> v >> c >> d;
        graph[v].push_back({u, c, d});
    }
}

int dp(int node, int total) {

    if (node == 1) return 0;
    if (memo[node][total] != -1) return memo[node][total];

    int re = 1e9;
    for (auto& [before, p, t] : graph[node]) {
        if (total-p < 0) continue;
        re = min(re, dp(before, total-p)+t);
    }

    return memo[node][total] = re;
}

int main() {

    cin >> T;
    while (T--) {
        getInput();
        int re = dp(N, M);
        if (re == 1e9) cout << "Poor KCM" << '\n';
        else cout << re << '\n';
    }
    return 0;
}