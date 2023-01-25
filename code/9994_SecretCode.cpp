#include <cstdio>
#include <cstring>
#include <cstring>
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

string s;
int memo[105][105];

int func(int st, int en) {

    int sz = en-st+1;
    if (sz <= 1 || !(sz%2)) return 0;
    if (memo[st][en] != -1) return memo[st][en];

    int cnt = 0, half = sz/2;
    string s1 = s.substr(st, half);
    string s2 = s.substr(st+1, half);
    string s3 = s.substr(st+half+1, half);
    string s4 = s.substr(st+half, half);

    if (s1 == s3) cnt += 1+func(st, st+half);
    if (s2 == s3) cnt += 1+func(st, st+half);
    if (s1 == s4) cnt += 1+func(st+half, en);
    if (s1 == s3) cnt += 1+func(st+half, en);

    return memo[st][en] = cnt;
}

int main() {

    cin >> s;

    for (int i=0; i<105; i++) {
        for (int j=0; j<105; j++)
            memo[i][j] = -1;
    }

    cout << func(0, s.size()-1);
    return 0;
}