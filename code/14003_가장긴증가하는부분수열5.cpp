#include <cstdio>
#include <cstring>
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
#define Y second

int N;
int A[1000005];
int L[1000005];
int P[1000005];

void trace(int idx, int num) {

    if (num < 0) return ;
    if (P[idx] == num) {
        trace(idx-1, num-1);
        cout << A[idx] << " ";
    }
    else trace(idx-1, num);
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];

    int len = 0;
    for (int i=0; i<N; i++) {
        int pos = lower_bound(L, L+len, A[i])-L;
        L[pos] = A[i];
        P[i] = pos;
        if (pos == len) len++;
    }

    cout << len << '\n';
    trace(N-1, len-1);
    return 0;
}