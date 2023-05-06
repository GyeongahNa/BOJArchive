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

int N, K, x, sum;
int f[100005];
priority_queue<iii, vector<iii>, less<iii>> pq;

void getInput() {

    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> f[i];
    }

    for (int i=0; i<N-1; i++) {
        int dist = f[i+1]-f[i];
        sum += dist;
        pq.push({dist, f[i], f[i+1]});
    }
}

int main() {

    getInput();

    if (K >= N) {
        cout << N;
        return 0;
    }

    for (int i=0; i<K-1; i++) {
        auto [dist, a, b] = pq.top();
        pq.pop();
        sum -= dist;
    }

    sum += K;
    cout << sum;
    return 0;
}