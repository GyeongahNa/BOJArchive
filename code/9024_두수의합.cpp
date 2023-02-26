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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int t, n, k, x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v;
        for (int i=0; i<n; i++) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        int mndiff = INT_MAX;
        int l = 0, r = n-1;
        while (r >= 0 && l < n && l < r) {
            int sum = v[l]+v[r];
            mndiff = min(mndiff, abs(k-sum));
            if (sum == k) break;
            else if (sum < k) l++;
            else r--;
        }

        int cnt = 0;
        for (int i=0; i<n; i++) {
            int num1 = k-v[i]-mndiff;
            int num2 = k-v[i]+mndiff;
            if (binary_search(v.begin(), v.end(), num1)) ++cnt;
            if (num1 != num2 && binary_search(v.begin(), v.end(), num2)) ++cnt;
        }
        cout << cnt/2 << '\n';
    }
    return 0;
}