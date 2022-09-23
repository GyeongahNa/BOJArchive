#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

bool isPrime(int x) {
    
    if (x < 2) return false;
    for (int i=2; i*i<=x; i++)
        if (x%i == 0) return false;
    return true;
}

int main() {
    
    int N;
    scanf("%d", &N);
    
    int cnt = 0;
    while (N--) {
        int x;
        scanf("%d", &x);
        if (isPrime(x)) cnt++;
    }
    printf("%d", cnt);
    return 0;
}