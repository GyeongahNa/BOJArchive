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

int N, x, y;
vector<int> ret;
vector<bool> visited(10005);
vector<vector<int>> graph(10005, vector<int>(0));

int dfs(int node) {

    visited[node] = true;

    int mx = 0, sum = 0;
    for (auto& next : graph[node]) {
        if (visited[next]) continue;
        int cnt = dfs(next);
        mx = max(cnt, mx);
        sum += cnt;
    }

    if (mx*2 <= N && (N-1-sum)*2 <= N) ret.push_back(node);
    return sum+1;
}

int main() {

    cin >> N;
    for (int i=0; i<N-1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    sort(ret.begin(), ret.end());
    for (auto& e : ret) cout << e << '\n';
    return 0;
}