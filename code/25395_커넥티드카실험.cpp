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

int dx[2] = {-1, 1};

int n, s;
vector<ii> v(1000005);
int visited[1000005];

void getInput() {

    cin >> n >> s;

    for (int i=1; i<=n; i++)
        cin >> v[i].X;

    for (int i=1; i<=n; i++)
        cin >> v[i].Y;
}

void bfs() {

    queue<ii> q;
    q.push({s, v[s].Y}); //(위치, 연료)
    visited[s] = v[s].Y;

    while (!q.empty()) {

        ii cur = q.front();
        auto [pos, f] = cur;
        q.pop();

        for (int i=0; i<2; i++) {
            int next = pos+dx[i];
            if (next < 1 || next > n) continue;
            int need = abs(v[pos].X-v[next].X);
            if (f < need) continue;

            int mx = max(f-need, v[next].Y);
            if (visited[next] >= mx) continue;

            q.push({next, mx});
            visited[next] = mx;
        }
    }
}

int main() {

    getInput();
    bfs();

    for (int i=1; i<=n; i++) {
        if (!visited[i]) continue;
        cout << i << " ";
    }
    return 0;
}