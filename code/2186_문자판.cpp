#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

string s;
int N, M, K;
int memo[105][105][85];
char board[105][105];

void getInput() {
    
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            for (int k=0; k<85; k++)
                memo[i][j][k] = -1;
        }
    }
    cin >> s;
}

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

int dfs(int x, int y, int idx) {

    if (idx+1 >= s.size()) return 1;
    if (memo[x][y][idx] != -1) return memo[x][y][idx];
   
    int cnt = 0;
    for (int i=0; i<4; i++) {
        int nx = x;
        int ny = y;
        for (int k=0; k<K; k++) {
            nx += dx[i];
            ny += dy[i];
            if (OOB(nx, ny) || board[nx][ny] != s[idx+1]) continue;
            cnt += dfs(nx, ny, idx+1);
        }
    }

    return memo[x][y][idx] = cnt;
}

int main() {

    getInput();

    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] != s[0]) continue;
            ans += dfs(i, j, 0);
        }
    }

    cout << ans;
    return 0;
}