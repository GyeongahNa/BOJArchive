#include <cstdio>
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

int N, x, y;
vector<ii> v;

int main() {

    cin >> N;

    long long tot = 0;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        v.emplace_back(x, y);
        tot += y;
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    for (int i=0; i<v.size(); i++) {
        sum += v[i].Y;
        if (sum >= (tot+1)/2) {
            cout << v[i].X;
            return 0;
        }
    }
    return 0;
}