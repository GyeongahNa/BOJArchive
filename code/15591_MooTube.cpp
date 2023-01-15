#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, Q;
vector<vector<ii>> graph(5005);

void getInput() {

    cin >> N >> Q;
    for (int i=0; i<N-1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }
}

int dfs(int x, int k, vector<bool>& visited) {

    visited[x] = true;
    
    int cnt = 1;
    for (auto& [node, w] : graph[x]) {
        if (visited[node]) continue;
        if (w < k) continue;
        cnt += dfs(node, k, visited);
    }
    return cnt;
}

int main() {

    getInput();

    while (Q--) {
        int k, v;
        cin >> k >> v;
        vector<bool> visited(5005, false);
        cout << dfs(v, k, visited)-1 << '\n';
    }

    return 0;
}