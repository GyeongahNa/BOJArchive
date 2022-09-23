
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
int w[10][10];
int re = 100000000;

void solve(int start, int n, vector<bool> check, int pay) {

    check[n] = true;
    for (int i=0; i<N; i++) {
        if (w[n][i] && !check[i])
            solve(start, i, check, pay+w[n][i]);
    }

    for (int i=0; i<N; i++) if (!check[i]) return;
    if (!w[n][start]) return ;
    if (re > pay+w[n][start]) re = pay+w[n][start];
    return ;
}

int main() {

    scanf("%d", &N);
    memset(w, 0, sizeof(w));
    for (int i=0; i<N*N; i++)
        scanf("%d", &w[i/N][i%N]);
    
    for (int i=0; i<N; i++) {
        vector<bool> check(N, false);
        solve(i, i, check, 0);
    }

    printf("%d", re);
    return 0;
}