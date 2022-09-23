#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    
    int N;

    scanf("%d", &N);
    if (N == 1) printf("J7\n");
    else if (N == 2) printf("K8\n");
    else if (N == 3) printf("L9\n");
    else printf("%c%c\n", ((N-4)%12+'A'), ((N-4)%10+'0'));
    return 0;
}