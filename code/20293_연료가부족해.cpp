#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int R, C, N, r, c, f;
int fuel[3005][3005];
int memo[3005][3005];

void getInput() {

    cin >> R >> C >> N;
    for (int i=0; i<N; i++) {
        cin >> r >> c >> f;
        fuel[r][c] = f;
    }

    for (int i=0; i<=R; i++) {
        for (int j=0; j<=C; j++)
            memo[i][j] = -1;
    }
}

bool OOB(int x, int y) {
    return x <= 0 || x > R || y <= 0 || y > C;
}

int dfs(int x, int y) {

    if (x == R && y == C) return 0;
    if (memo[x][y] != -1) return memo[x][y];

    int re = R*C+1;
    for (int i=0; i<2; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (OOB(nx, ny)) continue;
        int nf = dfs(nx, ny)+1-fuel[x][y];
        nf = max(nf, 0);
        re = min(re, nf);
    }
    return memo[x][y] = re;
}

int main() {

    getInput();
    cout << dfs(1, 1);
}