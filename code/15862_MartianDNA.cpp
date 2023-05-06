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
using iii = tuple<int, int, int>;

#define X first
#define y second

int N, K, R, B, Q;
int num[200005];
int mn[200005];

void getInput() {

    cin >> N >> K >> R;
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }
    for (int i=0; i<R; i++) {
        cin >> B >> Q;
        mn[B] = Q;
    }
}

bool check(int itv) {

    //기준 : mn
    //실제 : cnt
    //아직 충족 못한 수 : st
    vector<int> cnt(200005, 0);
    set<int> st;

    for (int i=0; i<itv; i++) {
        cnt[num[i]]++;
    }

    //[0, itv)
    for (int i=0; i<K; i++) {
        if (cnt[i] < mn[i]) {
            st.insert(i);
        }
    }

    if (!st.size()) {
        return true;
    }

    for (int i=1; i<N; i++) {
        if (i+itv-1 >= N) continue;

        int rm = num[i-1];
        int ad = num[i+itv-1];

        cnt[rm]--;
        if (cnt[rm] < mn[rm]) {
            st.insert(rm);
        }

        cnt[ad]++;
        if (cnt[ad] >= mn[ad]) {
            auto it = st.find(ad);
            if (it != st.end()) {
                st.erase(it);
            }
        }

        if (!st.size()) {
            return true;
        }
    }
    return false;
}

int binarySearch() {

    int first = 1;
    int last = N+1;
    int ret = last;

    while (first <= last) {
        int mid = (first+last)/2;
        if (check(mid)) {
            last = mid-1;
            ret = mid;
        }
        else first = mid+1;
    }
    return ret;
}

int main() {

    getInput();
    int ret = binarySearch();
    if (ret == N+1) {
        cout << "impossible";
        return 0;
    }
    cout << ret;
    return 0;
}