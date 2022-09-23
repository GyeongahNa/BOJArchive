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
    
    int N;
    scanf("%d", &N);
    
    while (N--) {
        
        int a, b;
        scanf("%d,%d", &a, &b);
        printf("%d\n", a+b);
    }
    
    return 0;
}