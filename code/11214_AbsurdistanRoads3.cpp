#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int n, a, b;
int indegree[100005];
bool visited[100005];
vector<int> graph[100005];


void getInput() {

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }
}

void RemoveLeaves() {

    queue<int> q;

    for (int i=1; i<=n; i++) {
        if (indegree[i] == 1) q.push(i);
    }

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (auto next : graph[cur]) {
            if (indegree[next] <= 1) continue;
            indegree[next]--;
            cout << cur << " " << next << '\n';
            if (indegree[next] == 1) q.push(next);
        }
    }
}

void dfs(int node, int st) {

    visited[node] = true;

    int cnt = 0;
    for (auto next : graph[node]) {
        if (indegree[next] == 1 || visited[next]) continue;
        cout << node << " " << next << '\n';
        ++cnt;
        dfs(next, st);
    }

    if (!cnt) cout << node << " " << st << '\n';
}

int main() {

    getInput();
    RemoveLeaves();

    for (int i=1; i<=n; i++) {
        if (indegree[i] == 1 || visited[i]) continue;
        dfs(i, i);
    }

    return 0;
}