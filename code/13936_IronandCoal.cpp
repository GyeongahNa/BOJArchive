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

int n, m, k, c, num;
vector<int> iron;
vector<int> coal;
vector<vector<int>> graph1(100005, vector<int>(0));
vector<vector<int>> graph2(100005, vector<int>(0));

void getInput() {

    cin>>n>>m>>k;
    for (int i=0; i<m; i++) {
        cin >> c;
        iron.push_back(c);
    }
    
    for (int i=0; i<k; i++) {
        cin >> c;
        coal.push_back(c);
    }

    for (int i=1; i<=n; i++) {
        cin >> num;
        for (int j=0; j<num; j++) {
            cin >> c;
            graph1[i].push_back(c);
            graph2[c].push_back(i);
        }
    }
}

vector<int> dijkstra(const vector<int>& v, const vector<vector<int>>& graph) {

    queue<ii> pq;
    vector<int> dist(n+1, 1e9);

    for (auto x : v) {
        pq.push({0, x});
        dist[x] = 0;
    }

    while (!pq.empty()) {

        ii cur = pq.front();
        pq.pop();

        if (dist[cur.Y] != cur.X) continue;

        for (auto next : graph[cur.Y]) {
            if (dist[next] > dist[cur.Y]+1) {
                dist[next] = dist[cur.Y]+1;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {

    getInput();
    
    vector<int> distStart = dijkstra({1}, graph1);
    vector<int> distIron = dijkstra(iron, graph2);
    vector<int> distCoal = dijkstra(coal, graph2);

    int ans = 1e9;
    for (int i=1; i<=n; i++) {
        if (distIron[i] == 1e9) continue;
        if (distCoal[i] == 1e9) continue;
        int d = distStart[i]+distIron[i]+distCoal[i];
        ans = min(ans, d);
    }

    if (ans == 1e9) cout<<"impossible";
    else cout<<ans;
    return 0;
}