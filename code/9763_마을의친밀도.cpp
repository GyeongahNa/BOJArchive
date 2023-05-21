#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<iii> coords;

void getInput() {

    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        coords.push_back({x, y, z});
    }
}

int dist(int idx1, int idx2) {

    auto [x1, y1, z1] = coords[idx1];
    auto [x2, y2, z2] = coords[idx2];

    return abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    getInput();

    int mn = 1e9;
    for (int i=0; i<N; i++) {

        vector<int> d;
        for (int j=0; j<N; j++) {
            if (j == i) continue;
            d.push_back(dist(i, j));
        }

        auto mnit1 = min_element(d.begin(), d.end());
        int mn1 = *mnit1;
        d.erase(mnit1);

        auto mnit2 = min_element(d.begin(), d.end());
        int mn2 = *mnit2;

        mn = min(mn, mn1+mn2);
    }

    cout << mn;
    return 0;
}