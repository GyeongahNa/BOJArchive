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

int N;
bool prime[1000000]; //소수가 아닐 때 true
int memo[1000][1000];

void eratos() {

    for (int i=0; i<1000; i++) {
        for (int j=0; j<1000; j++) 
            memo[i][j] = -1;
    }

    prime[1] = true;
    for (int i=2; i*i<1000000; i++) {
        if (prime[i]) continue;
        for (int j=i*i; j<1000000; j+=i) {
            prime[j] = true;
        }
    }
}

int concat(int x, int y) {
    return stoi(to_string(x)+to_string(y));
}

int dp(int x, int y) {

    if (x < 1 || y < 1) return 0;
    if (memo[x][y] != -1) return memo[x][y];
    bool p = !prime[concat(x, y)];
    int mx = max(dp(x-1, y), dp(x, y-1))+p;
    return memo[x][y] = mx;
}

int main() {

    cin >> N;
    eratos();

    cout << dp(N, N)-1;
    return 0;   
}