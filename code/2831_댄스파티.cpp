#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

int N, x;
vector<int> gsmall, gbig, msmall, mbig;

void getInput() {

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> x;
        if (x < 0) msmall.push_back(x);
        else mbig.push_back(x);
    }

    for (int i=0; i<N; i++) {
        cin >> x;
        if (x < 0) gsmall.push_back(x);
        else gbig.push_back(x);
    }
}

int cnt(vector<int> small, vector<int> big) {

    int idx = 0, re = 0;
    for (int i=0; i<(int)small.size() && idx <(int)big.size(); i++) {
        if (abs(small[i]) <= big[idx]) continue;
        ++re; ++idx;
    }
    return re;
}

int main() {

    getInput();

    sort(msmall.begin(), msmall.end(), greater<>());
    sort(gsmall.begin(), gsmall.end(), greater<>());
    sort(mbig.begin(), mbig.end());
    sort(gbig.begin(), gbig.end());

    cout << cnt(msmall, gbig)+cnt(gsmall, mbig);
    return 0;
}