#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, K;
int p[55];

void getInput() {

    cin >> N >> M >> K;
    for (int i=0; i<K; i++) {
        cin >> p[i];
    }
}

bool check(int mid, int mx) {

    int cnt = 0, prev = 0;
    for (int i=1; i<K; i++) {
        if (p[i]-p[prev] >= mid) {
            prev = i;
            continue;
        }
        ++cnt;
    }
    return cnt <= mx;
}

int binarySearch(int mx) {

    int first = 0;
    int last = N;
    int ret = 0;
    
    while (first <= last) {
        int mid = (first+last)/2;
        if (check(mid, mx)) {
            ret = mid;
            first = mid+1;
        }
        else last = mid-1;
    }

    return ret;
}

int main() {

    getInput();
    int d = binarySearch(K-M);

    string ret = "1";
    int prev = 0, cnt = 1;
    for (int i=1; i<K; i++) {
        if (cnt >= M || p[i]-p[prev] < d) ret += "0";
        else {
            ret += "1";
            prev = i;
            ++cnt;
        }
    }
    cout << ret;
    return 0;
}