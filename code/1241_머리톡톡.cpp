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

int N, x;
int A[100005];
int cnt[1000005];

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        ++cnt[A[i]];
    }

    for (int i=0; i<N; i++) {
        int num = 0;
        for (int j=1; j*j<=A[i]; j++) {
            if (A[i]%j) continue;
            int a = j;
            int b = A[i]/a;
            num += cnt[a];
            if (a == A[i]) --num;
            if (b == a) continue;
            num += cnt[b];
            if (b == A[i]) --num;
        }
        cout << num << '\n';
    }
    return 0;
}