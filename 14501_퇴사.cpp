#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

vector<int> vT, vP;

void solve(int idx, int total, int& max) {

    if (idx >= vT.size()) {
        if (idx == vT.size() && total > max) max = total;
        return;
    }
    solve(idx+vT[idx], total+vP[idx], max);
    solve(idx+1, total, max);
}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int time, pay;
        scanf("%d %d", &time, &pay);
        vT.push_back(time);
        vP.push_back(pay);
    }

    int max = 0;
    solve(0, 0, max);
    printf("%d", max);
    return 0;
}