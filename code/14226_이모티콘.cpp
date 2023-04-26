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

int S;
int dist[1005][2005];

int bfs() {

    for (int i=0; i<1005; i++) {
        for (int j=0; j<2005; j++) {
            dist[i][j] = 1e9;
        }
    }

    queue<ii> q;
    q.push({1, 0});
    dist[1][0] = 0;

    int mn = 1e9;
    while (!q.empty()) {
        ii cur = q.front();
        auto& [m, c] = cur;
        q.pop();

        if (m == S) {
            mn = min(mn, dist[m][c]);
        }

        vector<ii> next = {{m, m}, {m+c, c}, {m-1, c}};
        next.push_back({m, m});

        for (auto& [nextm, nextc] : next) {
            if (nextm < 0 || nextm > 1000) continue;
            if (dist[nextm][nextc] != 1e9) continue;
            q.push({nextm, nextc});
            dist[nextm][nextc] = dist[m][c]+1;
        }
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> S;
    cout << bfs();
    return 0;
}