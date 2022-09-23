#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    while (N != 0) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            int x;
            scanf("%d", &x);
            if (x == 0) cnt++;
        }

        printf("Mary won %d times and John won %d times\n", cnt, N-cnt);
        scanf("%d", &N);
    }
    return 0;
}