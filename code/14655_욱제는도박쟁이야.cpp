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
    
    int n1 = 0, n2 = 0;
    for (int i=0; i<2*N; i++) {
        int x;
        scanf("%d", &x);
        if (i < N) n1 += max(x, -x);
        else n2 += min(x, -x);
    }
    
    printf("%d", n1-n2);
    return 0;
}