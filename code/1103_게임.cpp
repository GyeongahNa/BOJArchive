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

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

char c;
int N, M;
int memo[55][55];
char board[55][55];
bool visited[55][55];

void getInput() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> c;
            board[i][j] = (c == 'H' ? 0 : c-'0');
            memo[i][j] = -1;
        }
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

int dfs(int x, int y) {

    visited[x][y] = true;
    if (memo[x][y] != -1) return memo[x][y];
    
    int ret = 1;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i]*board[x][y];
        int ny = y+dy[i]*board[x][y];
        if (OOB(nx, ny) || !board[nx][ny]) continue;
        if (visited[nx][ny]) {
            cout << -1;
            exit(0);
        }
        ret = max(ret, dfs(nx, ny)+1);
        visited[nx][ny] = false;
    }
    return memo[x][y] = ret;
}

int main() {

    getInput();
    cout << dfs(0, 0);
    return 0;
}