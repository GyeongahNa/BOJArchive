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

#define mod 1000000007

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define mod 1000000007

int T, x;
long long  dp[5005];

void dynamic() {
    
    dp[0] = 1; dp[1] = 1;
    for (int i=2; i<5005; i++) {        
        long long sum = 0;
        for (int j=0; j<=i-1; j++) {
            sum += dp[j]*dp[i-1-j]%mod;
            sum %= mod;
        }
        dp[i] = sum;
    }
}

int main() {

    dynamic();

    cin >> T;
    while (T--) {
        cin >> x;
        cout << dp[x+1] << "\n";
    }
    return 0;
}