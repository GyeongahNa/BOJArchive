#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

bool prime[1000001];

int main() {
    
    int T;
    scanf("%d", &T);
    memset(prime, false, sizeof(prime));

    prime[0] = true, prime[1] = true;
    for (int i=2; i<1000001; i++) {
        if (prime[i]) continue;
        for (int j=i*2; j<1000001; j+=i)
            prime[j] = true;
    }
    
    while (T--) {
        
        int N;
        scanf("%d", &N);
        
        int re = 0;
        for (int i=2; i<=N/2; i++) {
            if (prime[i] || prime[N-i]) continue;
            re++;
        }
        printf("%d\n", re);
    }
    return 0;
}