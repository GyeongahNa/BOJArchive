#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;;

#define X first
#define Y second

int T;
int n, m, t, s, g, h, a, b, d, x;

vector<int> ans, dest;
vector<vector<ii>> graph(2005);

void getInput() {

    ans.clear(); dest.clear();
    for (int i=0; i<2005; i++)
        graph[i].clear();

    cin >> n >> m >> t;
    cin >> s >> g >> h;

    for (int i=0; i<m; i++) {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    for (int i=0; i<t; i++) {
        cin >> x;
        dest.push_back(x);
    }
}

void dijkstra(int s, vector<int>& dist) {

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {

        ii cur = pq.top();
        auto [d, node] = cur;
        pq.pop();

        if (dist[node] != d) continue;

        for (auto [next, nextd] : graph[node]) {
            if (dist[next] > d+nextd) {
                dist[next] = d+nextd;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {

    cin >> T;
    while (T--) {

        getInput();

        vector<int> distS(2005, 1e9);
        vector<int> distG(2005, 1e9);
        vector<int> distH(2005, 1e9);

        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);

        for (auto x : dest) {
            if (distS[x] == distS[g]+distG[h]+distH[x]) ans.push_back(x);
            else if (distS[x] == distS[h]+distH[g]+distG[x]) ans.push_back(x);
        }

        sort(ans.begin(), ans.end());
        for (auto x : ans) cout << x << " ";
        cout << '\n';
    }
}