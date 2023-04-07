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

int sign[2] = {-1, 1};

int N;
long long A[105];
long long memo[105][1005];

void getInput() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    for (int i=0; i<105; i++) {
        for (int j=0; j<1005; j++)
            memo[i][j] = -1;
    }
}

long long dp(int i, int bf) {

    if (memo[i][bf] != -1) return memo[i][bf];

    if (i >= N) {
        if (bf == A[i]) return 1;
        return 0;
    }
    
    long long sum = 0;
    for (int k=0; k<2; k++) {
        int nbf = bf+sign[k]*A[i];
        if (nbf < 0 || nbf > 20) continue;
        sum += dp(i+1, nbf);
    }

    return memo[i][bf] = sum;
}

int main() {

    getInput();
    cout << dp(2, A[1]);
    return 0;
}