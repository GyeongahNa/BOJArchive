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
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    printf("%d", (N-1)+N*(M-1));
    return 0;
}