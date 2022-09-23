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

int N, K, B;
bool point[100001];

int main() {

    scanf("%d %d %d", &N, &K, &B);
    memset(point, true, sizeof(point));

    for (int i=0; i<B; i++) {
        int b;
        scanf("%d", &b);
        point[b] = false;
    }

    int cntB = 0;
    for (int i=1; i<=K; i++)
        if (!point[i]) cntB++;
    
    int minB = cntB;
    for (int i=2; i<= N-K+1; i++) {
        if (!point[i-1]) cntB--;
        if (!point[i+K-1]) cntB++;
        minB = min(minB, cntB);
    }
    printf("%d", minB);
    return 0;
}