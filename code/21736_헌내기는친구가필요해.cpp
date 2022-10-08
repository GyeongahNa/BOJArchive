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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, stx, sty;
char board[605][605];

int bfs(int x, int y) {

    queue<ii> q;
    q.push({x, y});

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[x][y] = true;

    int cnt = 0;
    while (!q.empty()) {

        ii cur = q.front();
        if (board[cur.X][cur.Y] == 'P') cnt++;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 'X' || visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return cnt;
}

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'I') {
                stx = i, sty = j;
            }
        }
    }

    int cnt = bfs(stx, sty);
    if (!cnt) cout<<"TT";
    else cout<<cnt;
    return 0;
}