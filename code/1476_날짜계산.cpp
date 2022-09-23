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
    
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    if (E%15 == 0) E = 0;
    if (S%28 == 0) S = 0;
    if (M%19 == 0) M = 0;


    for (int i=1; i<=10000; i++) {
        if (i%15 == E && i%28 == S && i%19 == M) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}