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
#define y second

int N, M, A, B, a, b;
bool visited[100005];
ii sec[105];

void getInput() {

    cin >> N >> M >> A >> B;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        sec[i] = {a, b};
    }
}

bool isInSection(int n) {

    for (int i=0; i<M; i++) {
        auto [s, e] = sec[i];
        if (n >= s && n <= e) {
            return true;
        }
    }
    return false;
}

int64_t bfs() {

    queue<ii> q;
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {

        auto [num, cnt] = q.front();
        q.pop();

        if (num == N) {
            return cnt;
        }

        int poss[] = {A, B};
        for (int i=0; i<2; i++) {
            int newNum = num+poss[i];
            if (newNum > N || visited[newNum]) continue;
            if (isInSection(newNum)) continue;
            q.push({newNum, cnt+1});
            visited[newNum] = true;
        }
    }

    return -1;
}

int main() {

    getInput();
    cout << bfs();
    return 0;
}