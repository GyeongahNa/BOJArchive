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

int N, M, b1, b2;
int mn = 1e9;
vector<vector<int>> graph(105, vector<int>(0));

void getInput() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

vector<int> dijkstra(int st) {

    queue<ii> pq;
    pq.push({0, st});

    vector<int> dist(N+1, 1e9);
    dist[st] = 0;

    while (!pq.empty()) {

        ii cur = pq.front();
        pq.pop();

        if (dist[cur.Y] != cur.X) continue;

        for (auto next : graph[cur.Y]) {
            if (dist[cur.Y]+1 < dist[next]) {
                dist[next] = dist[cur.Y]+1;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {

    getInput();

    for (int i=1; i<N; i++) {
        for (int j=i+1; j<=N; j++) {

            vector<int> dist1 = dijkstra(i);
            vector<int> dist2 = dijkstra(j);

            int sum = 0;
            for (int i=1; i<=N; i++) 
                sum += min(dist1[i], dist2[i])*2;
            if (sum < mn) {
                b1 = i;
                b2 = j;
                mn = sum;
            }
        }
    }

    cout<<b1<<" "<<b2<<" "<<mn;
    return 0;
}