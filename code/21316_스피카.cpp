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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int x, y;
vector<vector<int>> graph(13, vector<int>(0));

bool check(int node) {

    if (graph[node].size() != 3) return false;
    vector<int> v;
    for (auto next : graph[node]) {
        v.push_back(graph[next].size());
    }

    sort(v.begin(), v.end());
    return v[0] == 1 && v[1] == 2 && v[2] == 3;
 }

int main() {

    for (int i=1; i<=12; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x); 
    }

    for (int i=1; i<=12; i++) {
        if (check(i)) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}