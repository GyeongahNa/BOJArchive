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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
vector<ii> hole;
char board[2005][2005];
bool visited[2005][2005];

void getInput() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if ((i == 0 || i == N-1) && board[i][j] == '.') {
                hole.push_back({i, j});
            }
            if ((j == 0 || j == M-1) && board[i][j] == '.') {
                hole.push_back({i, j});
            }
        }
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

void dfs(int x, int y) {

    visited[x][y] = true;

    if (x == hole[1].X && y == hole[1].Y) {

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (board[i][j] == '.' && !visited[i][j]) {
                    cout << '@';
                }
                else {
                    cout << board[i][j];
                }
            }
            cout << '\n';
        }
        exit(0);
    }

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (OOB(nx, ny) || board[nx][ny] != '.' || visited[nx][ny]) continue;
        dfs(nx, ny);
        visited[nx][ny] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    getInput();
    dfs(hole[0].X, hole[0].Y);
    return 0;
}