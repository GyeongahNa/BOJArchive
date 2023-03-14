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

int T, n, d, c, a, b, s;

int main() {

    cin >> T;
    while (T--) {
        cin >> n >> d >> c;

        vector<int> dist(n+1, 1e9);
        vector<vector<ii>> graph(n+1, vector<ii>());

        for (int i=0; i<d; i++) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        queue<int> q;
        q.push(c);
        dist[c] = 0;

        while (!q.empty()) {

            int cur = q.front();
            q.pop();

            for (auto [next, t] : graph[cur]) {
                if (dist[next] <= dist[cur]+t) continue;
                q.push(next);
               dist[next] = dist[cur]+t;
            }
        }

        int cnt = 0, mxt = 0;
        for (int i=1; i<=n; i++) {
            if (dist[i] == 1e9) continue;
            ++cnt;
            mxt = max(mxt, dist[i]);
        }
        cout << cnt << " " << mxt << '\n';
    }
    return 0;
}