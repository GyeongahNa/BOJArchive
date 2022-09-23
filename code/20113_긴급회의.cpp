#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int pointed[102];

int main() {

    int N;
    scanf("%d", &N);

    memset(pointed, 0, sizeof(pointed));
    for (int i=1; i<=N; i++) {
        int p;
        scanf("%d", &p);
        if (p == 0) continue;
        pointed[p]++;
    }

    int maxp = max_element(pointed, pointed+N+1)-pointed;
    int cnt = 0;
    for (int i=1; i<=N; i++)
        if (pointed[i] == pointed[maxp]) cnt++;

    if (cnt >= 2) printf("skipped");
    else printf("%d", maxp);
    return 0;
}