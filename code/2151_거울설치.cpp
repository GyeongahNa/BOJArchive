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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int m[2][4] = {{3, 2, 1, 0}, {1, 0, 3, 2}};

int N, sx, sy, ex, ey;
string l;
char board[55][55];
bool visited[55][55][2505][4];

void getInput() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> l;
        for (int j=1; j<=N; j++) {
            board[i][j] = l[j-1];
            if (board[i][j] == '#') {
                if (!sx) { sx = i; sy = j;}
                else { ex = i; ey = j; }
            }
        }
    }
}

bool OOB(int x, int y) {
    return x < 1 || x > N || y < 1 || y > N;
}

int bfs() {

    queue<iiii> q;
    for (int i=0; i<4; i++) {
        q.push({sx, sy, 0, i});
        visited[sx][sy][0][i] = true;
    }

    int mn = INT_MAX;

    while (!q.empty()) {

        iiii cur = q.front();
        auto& [curx, cury, cnt, dir] = cur;
        if (curx == ex && cury == ey)
            mn = min(mn, cnt);
        q.pop();

        int nx = curx+dx[dir];
        int ny = cury+dy[dir];
        if (!OOB(nx, ny) && !visited[nx][ny][cnt][dir] && board[nx][ny] != '*') {
            q.push({nx, ny, cnt, dir});
            visited[nx][ny][cnt][dir] = true;
        }

        if (board[curx][cury] != '!') continue;

        for (int i=0; i<2; i++) {
            int nd = m[i][dir];
            int nx = curx+dx[nd];
            int ny = cury+dy[nd];
            if (OOB(nx, ny) || visited[nx][ny][cnt+1][nd] || board[nx][ny] == '*') continue;
            q.push({nx, ny, cnt+1, nd});
            visited[nx][ny][cnt+1][nd] = true;
        }
    }

    return mn;
}

int main() {

    getInput();
    cout << bfs();
}