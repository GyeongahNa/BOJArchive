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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char block[7] = {'|', '-', '+', '1', '2', '3', '4'};

int R, C, mx, my, zx, zy;
map<char, map<int, int>> m;
vector<vector<char>> board(30, vector<char>(30));

void getInput() {

    cin >> R >> C;
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'M') { mx = i, my = j; }
            if (board[i][j] == 'Z') { zx = i, zy = j; }
        }
    }

    m['|'].insert({1, 1});
    m['|'].insert({3, 3});
    m['-'].insert({0, 0});
    m['-'].insert({2, 2});
    m['1'].insert({3, 0});
    m['1'].insert({2, 1});
    m['2'].insert({1, 0});
    m['2'].insert({2, 3});
    m['3'].insert({0, 3});
    m['3'].insert({1, 2});
    m['4'].insert({0, 1});
    m['4'].insert({3, 2});
    
    for (int i=0; i<4; i++) {
        m['M'].insert({i, i});
        m['Z'].insert({i, i});
        m['+'].insert({i ,i});
    }
}

bool OOB(int x, int y) {
    return x < 1 || x > R || y < 1 || y > C;
}

bool bfs(const vector<vector<char>>& newb) {

    queue<iii> q;
    bool visited[30][30][4];

    for (int i=0; i<30; i++) {
        for (int j=0; j<30; j++) {
            for (int k=0; k<4; k++)
                visited[i][j][k] = false;
        }
    }

    for (int i=0; i<4; i++) {
        q.push({mx, my, i});
        visited[mx][my][i] = true;
    }

    while (!q.empty()) {

        iii cur = q.front();
        auto [x, y, d] = cur;
        if (x == zx && y == zy) return true;
        q.pop();

        int outd = m[newb[x][y]][d];
        int nx = x+dx[outd];
        int ny = y+dy[outd];
        if (newb[x][y] == 'M' && newb[nx][ny] == 'Z') continue;
        if (OOB(nx, ny) || newb[nx][ny] == '.' || visited[nx][ny][outd]) continue;
        if (m[newb[nx][ny]].find(outd) == m[newb[nx][ny]].end()) continue;

        q.push({nx, ny, outd});
        visited[nx][ny][outd] = true;
    }

    return false;
}

int main() {

    getInput();

    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (board[i][j] != '.') continue;
            for (int k=0; k<7; k++) {
                vector<vector<char>> newb = board;
                newb[i][j] = block[k];
                if (bfs(newb)) {
                    cout << i << " " << j << " " << block[k];
                    return 0;
                }
            }
        }
    }

    return 0;
}