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
    
    int re = 1;
    for (int i=2; i<=N; i++)
        re *= i;
    printf("%d", re);
    return 0;
}