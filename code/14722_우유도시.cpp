#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int N;
int board[1005][1005];
int memo[1005][1005][3];

void getInput() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<1005; i++) {
        for (int j=0; j<1005; j++) {
            for (int k=0; k<3; k++)
                memo[i][j][k] = -1;
        }
    }
}

int dp(int x, int y, int bf) {

    if (memo[x][y][bf] != -1) return memo[x][y][bf];

    int here = 0, nextBf = bf;
    if (board[x][y] == (bf+1)%3) {
        ++here;
        nextBf = board[x][y];
    }

    int mx = 0;
    for (int i=0; i<2; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        mx = max(mx, dp(nx, ny, nextBf));
    }

    return memo[x][y][bf] = here+mx;
}

int main() {

    getInput();

    int ans = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (board[i][j] != 0) continue;
            ans = max(ans, dp(i, j, 2));
        }
    }

   cout << ans;
    return 0;
}
