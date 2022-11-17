#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int arr[100005];
int dp[1000005];

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    int mx = 0;
    for (int i=0; i<N; i++) {
        dp[arr[i]] = dp[arr[i]-1]+1;
        mx = max(dp[arr[i]], mx);
    }

    cout<<mx;
    return 0;
}