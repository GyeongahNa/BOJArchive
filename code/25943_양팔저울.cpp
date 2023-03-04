#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int w[7] = {100, 50, 20, 10, 5, 2, 1};

int N, x;

int main() {

    cin >> N;

    int l = 0, r = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        if (l == r) l += x;
        else if (l < r) l += x;
        else r += x;
    }

    int diff = abs(l-r);

    int cnt = 0;
    for (int i=0; i<7; i++) {
        if (diff <= 0) break;
        if (diff < w[i]) continue;
        diff -= w[i];
        --i; ++cnt;
    }

    cout << cnt;
    return 0;
}