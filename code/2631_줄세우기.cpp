#include <cstdio>
#include <cstring>
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

int N;
int A[205];
int dp[205];

void getInput() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }
}

int main() {

    getInput();

    int mx = 0;
    for (int i=1; i<=N; i++) {
        dp[i] = 1;
        for (int j=1; j<=N; j++) {
            if (A[j] >= A[i]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
        mx = max(mx, dp[i]);
    }

    cout << N-mx;
    return 0;
}