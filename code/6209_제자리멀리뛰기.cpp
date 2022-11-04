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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int d, n, m, mnDist;
vector<int> rocks;

bool check(int mid) {

    int cnt = 0, pLast = 0;
    
    for (int i=1; i<rocks.size(); i++) {
        if (rocks[i]-rocks[pLast] < mid) cnt++;
        else pLast = i;
    }

    if (d-rocks[pLast] < mid) cnt++;
    return cnt <= m;
}

int binarySearch() {

    int first = mnDist;
    int last = d;
    int ret = 0;
    int mid;

    while (first <= last) {
        mid = (first+last)/2;
        if (check(mid)) {
            ret = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> d >> n >> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        rocks.push_back(x);
    }
    rocks.push_back(0);
    sort(rocks.begin(), rocks.end());

    cout<<binarySearch();
    return 0;
}