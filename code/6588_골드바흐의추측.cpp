#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

bool check[1000001];

int main() {
    
    memset(check, false, sizeof(check));
    
    for (int i=2; i<=1000000; i++) {
        if (check[i]) continue;
        for (int j=i*2; j<=1000000; j+=i)
            check[j] = true;
    }
    
    int d;
    scanf("%d", &d);
    
    while (d) {
        
        bool find = false;
        for (int i=3; i<=d; i++) {
            if (check[i] || i%2 == 0) continue;
            if (check[d-i] || (d-i)%2 == 0) continue;
            printf("%d = %d + %d\n", d, i, d-i);
            find = true;
            break;
        }
        if (!find) printf("Coldbach's conjecture is wrong.\n");
        scanf("%d", &d);
    }
    
    return 0;
}