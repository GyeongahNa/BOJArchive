#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    
    int t;
    scanf("%d", &t);
    
    while (t--) {
        
        int N;
        scanf("%d", &N);
        
        vector<int> v(N);
        for (int i=0; i<N; i++)
            scanf("%d", &v[i]);
        
        long long re = 0;
        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++)
                re += gcd(v[i], v[j]);
        }
        printf("%lld\n", re);
    }
    return 0;
}