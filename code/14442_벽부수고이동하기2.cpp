#include <cstdio>
#include <cstring>
#include <cmath>
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

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M, K;
char board[1005][1005];
int dist[1005][1005][15];

void getInput() {

    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++)
            cin >> board[i][j];
    }

    for (int i=0; i<1005; i++) {
        for (int j=0; j<1005; j++) {
            for (int k=0; k<15; k++)    
                dist[i][j][k] = 1e9;
        }
    }
}

bool OOB(int x, int y) {
    return x < 1 || x > N || y < 1 || y > M;
}

void bfs() {

    queue<iii> q;
    q.push({1, 1, K});
    dist[1][1][K] = 1;

    while (!q.empty()) {

        iii cur = q.front();
        auto [x, y, k] = cur;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (OOB(nx, ny)) continue;
            int nk = (board[nx][ny] == '1' ? k-1 : k);
            if (nk < 0) continue;
            if (dist[nx][ny][nk] != 1e9) continue;
            q.push({nx, ny, nk});
            dist[nx][ny][nk] = dist[x][y][k]+1;
        }
    }
}

int main() {

    getInput();
    bfs();
    
    int mn = 1e9;
    for (int i=0; i<=K; i++)
        mn = min(mn, dist[N][M][i]);
    
    if (mn == 1e9) cout << -1;
    else cout << mn;
    return 0;
}