#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N;
int A[8];
int re = -1;

void solve(int idx, vector<bool> check, int sum) {

    check[idx] = true;
    for (int i=0; i<N; i++) {
        if (check[i]) continue;
        solve(i, check, sum+max(A[idx]-A[i], A[i]-A[idx]));
    }
    if (re < sum) re = sum;
}

int main() {

    scanf("%d", &N);
    memset(A, 0, sizeof(A));

    for (int i=0; i<N; i++)
        scanf("%d", &A[i]);

    for (int i=0; i<N; i++) {
        vector<bool> check(N, false);
        int sum = 0;
        solve(i, check, sum);
    }
    printf("%d", re);
    return 0;
}