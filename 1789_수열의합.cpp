#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    
    long long S;
    scanf("%lld", &S);
    
    long long i = 2;
    while (i <= S) {
        if (i*(i+1)/2 > S) break;
        i++;
    }
    printf("%lld", i-1);
    return 0;
}