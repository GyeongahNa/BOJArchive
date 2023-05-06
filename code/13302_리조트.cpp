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
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, x;
int check[105];
int dp[105][105];

void getInput() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> x;
        check[x] = true;
    }
}

void dynamic() {

    for (int i=0; i<105; i++) {
        for (int j=0; j<105; j++) {
            dp[i][j] = 1e9;
        }
    }

    dp[0][0] = 0;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=100; j++) {

            if (check[i]) {
                dp[i][j] = dp[i-1][j];
                continue;
            }

            int mn = 1e9;
            
            //쿠폰
            mn = min(mn, dp[i-1][j+3]);

            //하루권
            mn = min(mn, dp[i-1][j]+10000);

            //3일권
            for (int k=1; k<=3; k++) {
                if (i-k < 0) continue;
                mn = min(mn, dp[i-k][j-1]+25000);
            }

            //5일권
            for (int k=1; k<=5; k++) {
                if (i-k < 0) continue;
                mn = min(mn, dp[i-k][j-2]+37000);
            }

            dp[i][j] = mn;
        }
    }
}

int main() {

    getInput();
    dynamic();
    
    int mn = 1e9;
    for (int c=0; c<=100; c++) {
        mn = min(mn, dp[N][c]);
    }
    cout << mn;
    return 0;
}