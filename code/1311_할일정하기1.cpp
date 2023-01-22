#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int D[25][25];
int dp[25][(1<<20)+5];

void getInput() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> D[i][j];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<(1<<N); j++)
            dp[i][j] = 1e9;
    }
}

void dynamic() {

    for (int i=0; i<N; i++)
        dp[0][1<<i] = D[0][i];

    for (int i=1; i<N; i++) {
        for (int num=0; num<(1<<N); num++) {

            int cnt = 0;
            int tmp = num;
            for (int j=0; j<N; j++) {
                if (tmp%2) cnt++;
                tmp /= 2;
            }
            if (cnt != (i+1)) continue;

            for (int j=0; j<N; j++) {
                if (!(num&(1<<j))) continue;
                dp[i][num] = min(dp[i][num], dp[i-1][num&(~(1<<j))]+D[i][j]);
            }
        }
    } 
}

int main() {

    getInput();
    dynamic();
    cout << dp[N-1][(1<<N)-1];
    return 0;
}