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

int m, n, c;
vector<int> xcost;
vector<int> ycost;
int memo[1005][1005];

void getInput() {

    cin >> m >> n;
    xcost.resize(m);
    ycost.resize(n);

    for (int i=1; i<=m-1; i++) {
        cin >> xcost[i];
    }

    for (int i=1; i<=n-1; i++) {
        cin >> ycost[i];
    }

    sort(xcost.begin()+1, xcost.end(), greater<int>());
    sort(ycost.begin()+1, ycost.end(), greater<int>());

    for (int i=0; i<1005; i++) {
        for (int j=0; j<1005; j++) {
            memo[i][j] = -1;
        }
    }
}

int dp(int x, int y) {

    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    if (x == 0 && y == 0) {
        return 0;
    }

    if (x == 0) {
        int sum = 0;
        for (int i=1; i<=y; i++) {
            sum += ycost[i];
        }
        return sum;
    }

    if (y == 0) {
        int sum = 0;
        for (int i=1; i<=x; i++) {
            sum += xcost[i];
        }
        return sum;
    }

    return memo[x][y] = min(dp(x-1, y)+xcost[x]*(y+1), dp(x, y-1)+ycost[y]*(x+1));
}

int main() {

    getInput();
    cout << dp(m-1, n-1) << endl;
    return 0;
}