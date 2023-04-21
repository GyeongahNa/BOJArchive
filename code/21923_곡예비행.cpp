#include <cstdio>
#include <cstring>
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

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, 1, 0};

int N, M;
long long board[1005][1005];
long long memo[1005][1005][2];

void getInput() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<1005; i++) {
        for (int j=0; j<1005; j++) {
            for (int k=0; k<2; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
}

bool OOB(int x, int y) {
    return x < 1 || x > N || y < 1 || y > M;
}

long long dfs(int x, int y, int dir) {

    if (x == N && y == M && dir == 2) {
        return board[x][y];
    }

    if (memo[x][y][dir] != -1) {
        return memo[x][y][dir];
    }

    if (dir == 1) {
        long long mx = -1e10;
        for (int i=0; i<2; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (OOB(nx, ny)) continue;
            mx = max(mx, dfs(nx, ny, 1));
        }
        mx = max(mx, dfs(x, y, 2));
        return memo[x][y][dir] = mx+board[x][y];
    }

    long long mx = -1e10;
    for (int i=2; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (OOB(nx, ny)) continue;
        mx = max(mx, dfs(nx, ny, 2));
    }
    return memo[x][y][dir] = mx+board[x][y];
}

int main() {

    getInput();
    cout << dfs(N, 1, 1);
    return 0;
}