#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    
    int M;
    scanf("%d", &M);

    int a, b, S;
    int dir = 1;
    long long num = 1;
    for (int i=0; i<M; i++) {
    
        scanf("%d %d %d", &a, &b, &S);
        num = num / a * b;
        if (S == 1) dir *= -1;
    }
    
    dir = (dir == 1) ? 0 : 1;
    printf("%d %lld\n", dir, num);
    return 0;
}