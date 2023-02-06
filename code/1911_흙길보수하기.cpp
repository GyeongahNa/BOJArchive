#include <cstdio>
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

int N, L, s, e;
vector<ii> v;

int main() {

    cin >> N >> L;
    for (int i=0; i<N; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    int start = 0, tot = 0;
    for (int i=0; i<N; i++) {
        if (start < v[i].X) start = v[i].X;
        if (v[i].Y - start <= 0) continue;
        int cnt = (v[i].Y-start+L-1)/L;
        start += cnt*L;
        tot += cnt;
    }

    cout << tot;
    return 0;
}