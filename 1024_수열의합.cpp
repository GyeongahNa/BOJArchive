#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int main() {

    int N, L;
    scanf("%d %d", &N, &L);

    for (int i=L; i<=100; i++) {
        
        if ((2*N-i*i+i)%(2*i) != 0 || (2*N-i*i+i)/(2*i) < 0) continue;
        int num = (2*N-i*i+i)/(2*i);
        for (int j=0; j<i; j++)
            printf("%d ", num++);
        return 0;
    }
    printf("%d", -1);
    return 0;
}