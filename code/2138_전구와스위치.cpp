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
string src, dst;
vector<char> v1, v2;

char op(char x) {
    return x == '1' ? '0' : '1';
}

int cntN(vector<char>& v) {

    int cnt = 0;
    for (int i=1; i<N; i++) {
        if (v[i-1] == dst[i-1]) continue;
        v[i-1] = op(v[i-1]);
        v[i] = op(v[i]);
        if (i+1 < N) v[i+1] = op(v[i+1]);
        ++cnt;
    }
    return cnt;
}

int main() {

    cin >> N;
    cin >> src >> dst;

    for (int i=0; i<N; i++) {
        v1.push_back(src[i]);
        v2.push_back(src[i]);
    }

    v2[0] = op(v2[0]);
    v2[1] = op(v2[1]);

    int ans = 1e9;
    int cnt1 = cntN(v1);
    int cnt2 = cntN(v2)+1;

    if (v1[N-1] == dst[N-1]) ans = min(ans, cnt1);
    if (v2[N-1] == dst[N-1]) ans = min(ans, cnt2);

    if (ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}
