#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

char c;
bool board[10][10][9]; 
bool visited[10][10][9];

void getInput() {

    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            cin >> c;
            if (c == '#') board[i][j][0] = 1;
        }
    }

    for (int k=1; k<=8; k++) {
        for (int i=1; i<=8; i++) {
            for (int j=1; j<=8; j++)
                board[i][j][k] = board[i-1][j][k-1];
        }
    }
}

bool OOB(int x, int y) {
    return x < 1 || x > 8 || y < 1 || y > 8;
}

int bfs() {

    queue<iii> q;
    q.push({8, 1, 0});
    visited[8][1][0] = true;

    while (!q.empty()) {

        iii cur = q.front();
        auto [x, y, t] = cur;
        q.pop();

        if (x == 1 && y == 8) return 1;
        if (board[x][y][t]) continue;

        for (int i=0; i<9; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nt = (t >= 8 ? t : t+1);
            if (OOB(nx, ny) || board[nx][ny][t]) continue;
            if (visited[nx][ny][nt]) continue;
            q.push({nx, ny, nt});
            visited[nx][ny][nt] = true;
        }
    }

    return 0;
}

int main() {

    getInput();
    cout << bfs();
    return 0;
}