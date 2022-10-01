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
using ll = long long;

#define X first
#define Y second

set<ll> squ;
set<ll> tri;
vector<ll> v;

int main() {

    ll sum = 0;
    for (ll i=1; i<=50000; i++) {
        squ.insert(i*i);
        sum += i;
        tri.insert(sum);
    }

    for (ll i=1; i<=50000; i++) {
        if (squ.find(i*i) == squ.end()) continue;
        if (tri.find(i*i-1) == tri.end()) continue;
        v.push_back(i*i);
    }

    int nc = 1;
    while (true) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) return 0;
        auto it1 = lower_bound(v.begin(), v.end(), b);
        auto it2 = upper_bound(v.begin(), v.end(), a);
        cout<<"Case "<<nc++<<": "<<it1-it2<<endl;
    }
    return 0;
}