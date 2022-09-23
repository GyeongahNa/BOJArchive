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
   
    int N, S;
    scanf("%d %d", &N, &S);
    
    int g = 0;
    for (int i=0; i<N; i++) {
        int x, d;
        scanf("%d", &x);
        d = max(S-x, x-S);
        if (i == 0) g = d;
        else g = gcd(g, d);
    }
    printf("%d", g);
    return 0;
}