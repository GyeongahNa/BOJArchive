#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using lii = tuple<long long, int, int>;

#define X first
#define Y second
#define F10 3628800

int N, M, A, B, L, K;
vector<iii> graph[10005];
long long res[10005][15];

int dx[3] = { -1, 1, 0 };

void getInput() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B >> L >> K;
        graph[A].push_back({B, L, K});
        graph[B].push_back({A, L, K});
    }

    for (int i=0; i<10005; i++) {
        for (int j=0; j<15; j++)
            res[i][j] = 1e18;
    }
}

void dijkstra() {

    priority_queue<lii, vector<lii>, greater<>> pq;
    
    pq.push({0, 1, 1});
    res[1][1] = 0;
    
    while (!pq.empty()) {

        lii cur = pq.top();
        auto [t, node, speed] = cur;

        pq.pop();

        if (t != res[node][speed]) continue;

        for (int i=0; i<3; i++) {
            int nspeed = speed+dx[i];
            if (nspeed < 1) continue;
            for (auto [next, len, lim] : graph[node]) {
                if (nspeed > lim) continue;
                long long ntime = res[node][speed]+1LL*len*F10/nspeed;
                if (ntime < res[next][nspeed]) {
                    res[next][nspeed] = ntime;
                    pq.push({ntime, next, nspeed});
                }
            }
        }
    }
}

int main() {

    getInput();
    dijkstra();

    long long re = 1e18;
    for (int i=1; i<=10; i++)
        re = min(re, res[N][i]);

    cout << re / F10;
    re %= F10;

    char buf[15];
    sprintf(buf, "%.9f", (double)re/F10);
    string str = buf;
    cout << str.substr(1);

    return 0;
}