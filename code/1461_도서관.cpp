#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii =tuple<int, int, int>;

#define X first
#define Y second

int N, M, x;
vector<int> pos, neg;

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> x;
        if (x > 0) pos.push_back(x);
        if (x < 0) neg.push_back(x);
    }

    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());

    int step = 0, psz = pos.size(), nsz = neg.size();
    if (!psz || (psz && nsz && abs(pos[0]) < abs(neg[0]))) {
        step += abs(neg[0]);
        neg.erase(neg.begin(), neg.begin()+min(M, nsz));
    }
    else {
        step += abs(pos[0]);
        pos.erase(pos.begin(), pos.begin()+min(M, psz));
    }

    int idx = 0;
    while (idx < (int)pos.size()) {
        step += abs(pos[idx])*2;
        idx += M;
    }

    idx = 0;
    while (idx < (int)neg.size()) {
        step += abs(neg[idx])*2;
        idx += M;
    }

    cout << step;
    return 0;

}