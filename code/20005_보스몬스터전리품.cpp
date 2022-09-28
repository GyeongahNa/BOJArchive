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

char p;
int M, N, P, d, HP, stx, sty;
char board[1005][1005];
int dist[1005][1005];
map<char, int> dps;
vector<ii> v;

void getInput() {

    cin >> M >> N >> P;

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                stx = i, sty = j;
            }
        }
    }

    for (int i=0; i<P; i++) {
        cin >> p >> d;
        dps[p] = d;
    }

    cin >> HP;

    for (int i=0; i<1005; i++) {
        for (int j=0; j<1005; j++) 
            dist[i][j] = -1;
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= M || y < 0 || y >= N;
}

void bfs() {

    queue<ii> q;
    q.push({stx, sty});
    dist[stx][sty] = 0;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] == 'X' || dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }
}

int main() {

    getInput();
    bfs();

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] >= 'a' && board[i][j] <= 'z') 
                v.push_back({dist[i][j], dps[board[i][j]]});
        }
    }

    sort(v.begin(), v.end());

    int t = 0, sum = 0, idx = 0;
    while (HP > 0) {
        while (idx < (int)v.size() && v[idx].X == t) sum += v[idx++].Y;
        HP -= sum;
        t++;
    }
    cout<<idx;
    return 0;
}