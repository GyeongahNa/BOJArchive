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

int N, M, x, y;
vector<ii> v;

void getInput() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
}

bool check(ll mid) {

    ll total = 0, rec = 0;
    for (int i=0; i<(int)v.size(); i++) {
        if (rec < v[i].X) rec = v[i].X;
        else if (rec > v[i].Y) continue;

        int cnt = (v[i].Y-rec)/mid;
        total += (cnt+1);
        rec = rec+mid*cnt+mid;
    }

    return total >= N;
}

ll binarySearch() {

    ll first = 1;
    ll last = 1e18;
    ll ret = 1;

    while (first <= last) {
        ll mid = (first+last)/2;
        if (check(mid)) {
            first = mid+1;
            ret = mid;
        }
        else last = mid-1;
    }
    return ret;
}

int main() {

    getInput();
    cout << binarySearch();
    return 0;
}