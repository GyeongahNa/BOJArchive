#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int G, P;
int g[100005];
int parent[100005];

void initialize() {
    for (int i=1; i<=G; i++)
        parent[i] = i;
}

int find(int u) {
    if (parent[u] == u) return parent[u];
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u > v) swap(u, v);
    parent[v] = u;
}

void getInput() {

    cin >> G >> P;
    for (int i=0; i<P; i++) cin >> g[i];
}

int main() {

    getInput();
    initialize();

    int cnt = 0;
    for (int i=0; i<P; i++) {
        int pt = find(g[i]);
        if (pt != 0) {
            merge(pt, pt-1);
            cnt++;
        }
        else break;
    }

    cout << cnt;
    return 0;
}