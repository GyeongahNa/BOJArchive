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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };

int R, C;
char board[10005][505];
bool visited[10005][505];

void getInput() {

    cin >> R >> C;
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cin >> board[i][j];
        }
    }
}

bool dfs(int x, int y) {

    visited[x][y] = true;
    if (y == C) return true;

    for (int i=0; i<3; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
        if (board[nx][ny] == 'x' || visited[nx][ny]) continue;
        if (dfs(nx, ny)) return true;
    }
    return false;
}

int main() {

    getInput(); 
    
    int cnt = 0;
    for (int i=1; i<=R; i++) {
        if (dfs(i, 1)) ++cnt;
    }
    cout << cnt;
    return 0;
}