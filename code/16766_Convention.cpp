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

#define X first
#define Y second

int N, M, C;
int tt[100005];

void getInput() {

    cin >> N >> M >> C;
    for (int i=0; i<N; i++) {
        cin >> tt[i];
    }
    sort(tt, tt+N);
}

bool check(int t) {

    int idx = 0;
    for (int i=0; i<M; i++) {
        int cnt = 0;
        int st = idx;
        while (idx < N && cnt < C && tt[idx]-tt[st] <= t) {
            idx++;
            cnt++;
        }
    }

    return idx >= N;
}

int binarySearch() {

    int first = 0;
    int last = 1e9;
    int ret = last;

    while (first <= last) {
        int mid = (first+last)/2;
        if (check(mid)) {
            ret = mid;
            last = mid-1;
        }
        else first = mid+1;
    }

    return ret;
}

int main() {

    getInput();
    cout << binarySearch();
    return 0;
}