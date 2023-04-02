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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int n, k;
int board[55][55];
int memo[55][55];
vector<ii> coords[2505];

void getInput() {

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> board[i][j];
            coords[board[i][j]].push_back({i, j});
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++)
            memo[i][j] = -1;
    }
}

int dp(int x, int y) {

    int num = board[x][y];
    if (num == 1) return 0;
    if (memo[x][y] != -1) return memo[x][y];

    int mn = 1e9;
    for (auto [nx, ny] : coords[num-1]) {
        int dist = dp(nx, ny) + (abs(x-nx)+abs(y-ny));
        mn = min(dist, mn);
    }

    return memo[x][y] = mn;
}

int main() {

    getInput();

    int mn = 1e9;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (board[i][j] != k) continue;
            mn = min(mn, dp(i, j));
        }
    }

    if (mn == 1e9) cout << -1;
    else cout << mn;
    return 0;
}