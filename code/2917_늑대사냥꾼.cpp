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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, stx, sty, mx;
int dist[505][505];
int route[505][505];
char board[505][505];

void getInput() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'V') {
                stx = i, sty = j;
            }
        }
    } 
}

bool OOB(int x,  int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

void getDist() {

    queue<ii> q;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) { 
            dist[i][j] = 1e9;
            if (board[i][j] == '+') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (OOB(nx, ny) || dist[nx][ny] != 1e9) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }
}

void getRoute() {

    queue<iii> q;

    q.push({stx, sty, dist[stx][sty]});
    route[stx][sty] = dist[stx][sty];

    while (!q.empty()) {

        iii cur = q.front();
        auto& [x, y, d] = cur;
        q.pop();

        if (board[x][y] == 'J') mx = max(mx, route[x][y]);

        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (OOB(nx, ny)) continue;

            int mn = min(d, dist[nx][ny]);
            if (route[nx][ny] < mn) {
                route[nx][ny] = mn;
                q.push({nx, ny, route[nx][ny]});
            }
        }
    } 
}

int main() {

    getInput();
    getDist();
    getRoute();
    cout << mx;
    return 0;
} 