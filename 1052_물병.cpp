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

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    if (N <= K) {
        printf("0"); return 0;
    }

    int cnt = N, nBottle = N-1;
    while (cnt > K) {
        cnt = 0;
        nBottle++;
        int tmp = nBottle;
        while (tmp) {
            if (tmp%2) cnt++;
            tmp /= 2;
        }
    }
    printf("%d", nBottle-N);
    return 0;
}