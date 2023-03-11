#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using dii = tuple<double, int, int>;

#define X first
#define Y second

int N;
double x, y;
vector<dd> v;
vector<dii> dist;
vector<int> parent(105), nrank(105, 0);

void initialize() {

    for (int i=0; i<105; i++)
        parent[i] = i;
}

int find(int u) {

    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u == v) return ;
    if (nrank[u] > nrank[v]) swap(u, v);
    if (nrank[u] == nrank[v]) nrank[v]++;
    parent[u] = v;
}

double getDistance(ii a, ii b) {

    return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}

void getInput() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            dist.push_back({getDistance(v[i], v[j]), i, j});
        }
    }

    sort(dist.begin(), dist.end());
}

int main() {

    getInput();
    initialize();

    double ans = 0;
    for (auto [d, n1, n2] : dist) {
        if (find(n1) == find(n2)) continue;
        merge(n1, n2);
        ans += d;
    }

    cout << ans;
    return 0;
}