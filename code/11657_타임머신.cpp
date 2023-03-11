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
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, A, B, C;
vector<iii> v;
vector<long long> dist(505, LLONG_MAX);

void getInput() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B >> C;
        v.push_back({ A, B, C });
    }
}

int bellmanford() {

    dist[1] = 0;

    for (int i=0; i<N; i++) {
        for (auto [s, e, d] : v) {
            if (dist[s] == LLONG_MAX) continue;
            if (dist[s]+d < dist[e]) {
                dist[e] = dist[s]+d;
                if (i == N-1) return -1;
            }
        }
    }

    return 0;
}

int main() {

    getInput();
    if (bellmanford() == -1) {
        cout << -1;
        return 0;
    }

    for (int i=2; i<=N; i++) {
        if (dist[i] == LLONG_MAX) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}