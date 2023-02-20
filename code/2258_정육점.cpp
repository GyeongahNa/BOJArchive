#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, w, c;
vector<ii> v;

bool cmp(ii a, ii b) {

    if (a.Y < b.Y) return true;
    if (a.Y > b.Y) return false;
    return a.X > b.X;
}

void getInput() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> w >> c;
        v.push_back({w, c});
    }
    sort(v.begin(), v.end(), cmp);
}

int main() {

    getInput();
    
    int sum = 0, re = INT_MAX;
    for (int i=0; i<N; i++) {
        int j, p = 0;
        for (j=i; j<N && v[j].Y == v[i].Y; j++) {
            sum += v[j].X;
            p += v[j].Y;
            if (sum >= M) re = min(re, p);
        }
        i = j-1;
    }

    if (sum < M) cout << -1;
    else cout << re;
    return 0;
}