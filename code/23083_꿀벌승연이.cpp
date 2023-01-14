#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
int mod  = 1e9+7;

int dx[6] = { -1, 0, 1, 0, 1, 1 };
int dy[6] = { 1, 1, 0, 1, 1, 0 };

int N, M, K, x, y;
int memo[1005][1005];
int board[1005][1005];

int dfs(int x, int y) {

    if (x == N && y == M) return 1;
    if (memo[x][y] != -1) return memo[x][y];

    int ret = 0, st = 0, en = 3;
    
    if (y%2 == 0) {
        st = 3;
        en = 6;
    }

    for (int i=st; i<en; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > N) continue;
        if (ny < 1 || ny > M) continue;
        if (board[nx][ny]) continue;
        ret = (ret + dfs(nx, ny)) % mod;
    }

    memo[x][y] = ret;
    return memo[x][y];
}

int main() {

    cin >> N >> M >> K;
    for (int i=0; i<K; i++) {
        cin >> x >> y;
        board[x][y] = 1;
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++)
            memo[i][j] = -1;
    }

   cout << dfs(1, 1);
   return 0;
}