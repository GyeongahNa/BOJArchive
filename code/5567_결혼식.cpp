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
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, cnt;
vector<vector<int>> graph(505, vector<int>(0));
vector<bool> visited(505);

void bfs() {

    queue<int> q;
    q.push(1);
    visited[1] = true;

    int idx = 0;
    while (!q.empty()) {
        
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int i=0; i<graph[cur].size(); i++) {
                int next = graph[cur][i];
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
        if (idx >= 2) break;
        idx++; 
    }
}

int main() {

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();
    printf("%d", --cnt);
    return 0;
}