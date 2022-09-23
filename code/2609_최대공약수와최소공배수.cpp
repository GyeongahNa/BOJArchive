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
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d\n", gcd(a, b));
    printf("%d\n", a*b/gcd(a, b));
    return 0;
}