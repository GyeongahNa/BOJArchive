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

int n;
int A[2005];
int dp[2005];

int main() {

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> A[i];
    }

    int mx = 0;
    for (int i=1; i<=n; i++) {
        dp[i] = 1;
        for (int j=1; j<i; j++) {
            if (A[j] <= A[i]) continue;
            dp[i] = max(dp[j]+1, dp[i]);
        }
        mx = max(dp[i], mx);
    }

    cout << n-mx;
    return 0;
}