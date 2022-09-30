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
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int W, H, stx, sty, ex, ey;
int dist[505][505];
char board[505][505];

void setInput() {

    cin >> W >> H;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'T') {
                stx = i, sty = j;
            }
            else if (board[i][j] == 'E') {
                ex = i, ey = j;
            }
        }
    }

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++)
            dist[i][j] = 1e9;
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= H || y < 0 || y >= W;
}

bool check(int x, int y) {

    if (OOB(x, y)) return false;
    if (board[x][y] == 'H') return false;
    if (board[x][y] == 'R') return false;
    if (board[x][y] == 'E') return false;
    return true;
}

void dijkstra() {

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, stx, sty});
    dist[stx][sty] = 0;

    while (!pq.empty()) {

        int d, curx, cury;
        tie(d, curx, cury) = pq.top();
        pq.pop();
        if (dist[curx][cury] != d) continue;
        if (board[curx][cury] == 'E') continue;

        for (int i=0; i<4; i++) {

            int t = 0, x = curx, y = cury;
            while (check(x+dx[i], y+dy[i])) {
                x += dx[i];
                y += dy[i];
                t += (board[x][y]-'0');
            }

            int nx = x+dx[i];
            int ny = y+dy[i];

            if (OOB(nx, ny) || board[nx][ny] == 'H') continue;
            if (board[nx][ny] == 'R') {
                if (dist[curx][cury]+t < dist[x][y]) {
                    dist[x][y] = dist[curx][cury]+t;
                    pq.push({dist[x][y], x, y});
                }
                continue;
            }
            if (dist[curx][cury]+t < dist[nx][ny]) {
                dist[nx][ny]=  dist[curx][cury]+t;
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
}

int main() {

    setInput();
    dijkstra();
    
    if (dist[ex][ey] == 1e9) cout<<-1;
    else cout<<dist[ex][ey];
    return 0;
}