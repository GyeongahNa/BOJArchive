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
using ii = pair<int, int>;;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int W, H, stx, sty;
char board[105][105];
int mn = 105*105;

void getInput() {

    cin >> W >> H;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'C') {
                stx = i; sty = j;
            }
        }
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= H || y < 0 || y >= W;
}

void dfs(int x, int y, int d, int cnt, vector<vector<bool>>& visited) {

    visited[x][y] = true;

    if (board[x][y] == 'C' && x != stx && y != sty) {
        mn = min(mn, cnt);
        return ;
    }

    if (x == stx && y == sty) {
        int nx = x+dx[d];
        int ny = y+dy[d];
        if (OOB(nx, ny) || board[nx][ny] == '*') return ;
        dfs(nx, ny, d, cnt, visited);
        return ;
    }

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (OOB(nx, ny) || board[nx][ny] == '*' || visited[nx][ny]) continue;
        if (i == d) dfs(nx, ny, i, cnt, visited);
        else dfs(nx, ny, i, cnt+1, visited);
        visited[nx][ny] = false;
    }
}

int main() {

    getInput();
    
    for (int i=0; i<4; i++) {
        vector<vector<bool>> visited(105, vector<bool>(105, false));
        dfs(stx, sty, i, 0, visited);
    }

    cout << mn << '\n';
    return 0;
}