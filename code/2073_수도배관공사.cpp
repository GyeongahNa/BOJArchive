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

int D, P;
int dp[100005];
int L[355], C[355];

void getInput() {

    cin >> D >> P;
    for (int i=1; i<=P; i++) {
        cin >> L[i] >> C[i];
    }
}

void dynamic() {

    for (int i=1; i<=P; i++) {
        for (int j=D; j>=1; j--) {
            if (j < L[i]) continue;
            if (j == L[i]) dp[j] = max(dp[j], C[i]);
            else dp[j] = max(dp[j], min(dp[j-L[i]], C[i]));
        }
    }
}

int main() {

    getInput();
    dynamic();
    cout << dp[D];
    return 0;
}