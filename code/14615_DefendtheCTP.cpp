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

int N, M, x, y, T, C;
vector<vector<int>> graph1(100005, vector<int>(0));
vector<vector<int>> graphN(100005, vector<int>(0));
vector<bool> visited1(100005, false);
vector<bool> visitedN(100005, false);

void bfs(int st, const vector<vector<int>>& graph, vector<bool>& visited) {

    visited[st] = true;
    
    queue<int> q;
    q.push(st);

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int x : graph[cur]) {
            if (visited[x]) continue;
            q.push(x);
            visited[x] = true;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        graph1[x].push_back(y);
        graphN[y].push_back(x);
    }

    bfs(1, graph1, visited1);
    bfs(N, graphN, visitedN);

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &C);
        if (visited1[C] && visitedN[C]) printf("Defend the CTP\n");
        else printf("Destroyed the CTP\n");
    }
    return 0;
}