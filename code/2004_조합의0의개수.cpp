#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

long long getcnt(long long d, long long n) {
    
    long long re = 0;
    for (long long i=d; i<=n; i*=d)
        re += n/i;
    return re;
}

int main() {
    
    long long n, m;
    scanf("%lld %lld", &n, &m);
   
    long long cnt5 = getcnt(5, n)-getcnt(5, n-m)-getcnt(5, m);
    long long cnt2 = getcnt(2, n)-getcnt(2, n-m)-getcnt(2, m);
    
    printf("%lld", min(cnt5, cnt2));
    return 0;
}