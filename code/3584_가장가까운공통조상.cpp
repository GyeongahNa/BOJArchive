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

int T, N, p, c, node1, node2;
vector<int> parent(10001);
vector<bool> visited(10001);
vector<vector<int>> child(10001, vector<int>(0));

void getInput() {

    for (int i=0; i<10001; i++) {
        parent[i] = 0;
        visited[i] = false;
        child[i].clear();
    }

    for (int i=0; i<N-1; i++) {
        cin >> p >> c;
        parent[c] = p;
        child[p].push_back(c);
    }
}

bool bfs(int root) {

    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {

        int cur = q.front();
        if (cur == node2) return true;
        q.pop();

        for (auto next : child[cur]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }

    return false;
}

int getAns() {

    while (node1) {
        if (bfs(node1)) return node1;
        node1 = parent[node1];
    }
    return 0;
}


int main() {

    cin >> T;
    while (T--) {
        cin >> N;
        getInput();
        cin >> node1 >> node2;
        cout << getAns() << '\n';   
    }

    return 0;
}