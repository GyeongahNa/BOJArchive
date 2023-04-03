#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
int A[105];
int dp[10005];

void getInput() {

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        cin >> A[i];
    }

    for (int i=1; i<=N; i++) {
        dp[i] = 1e9;
    }
}

int main() {

    getInput();

    for (int i=1; i<=N; i++) {

        for (int j=1; j<=M; j++) {
            if (i-A[j] < 0) continue;
            dp[i] = min(dp[i], dp[i-A[j]]+1);
        }

        for (int j=1; j<=M; j++) {
            for (int k=j+1; k<=M; k++) {
                int sum = A[j]+A[k];
                if (i-sum < 0) continue;
                dp[i] = min(dp[i], dp[i-sum]+1);
            }
        }
    }

    if (dp[N] == 1e9) cout << -1;
    else cout << dp[N];
    return 0;
}