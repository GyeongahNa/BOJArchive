#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

long long dig[11] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999};
long long big[11] = {0, 4, 49, 499, 4999, 49999, 499999, 4999999, 49999999, 499999999, 4999999999};

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        long long N;
        scanf("%lld", &N);

        int d = to_string(N).size();
        long long re = big[d]*(dig[d]-big[d]);
        if (N < big[d]) re = N*(dig[d]-N);
        printf("%lld\n", re);
    }    
    return 0;
}