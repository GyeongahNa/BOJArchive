#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for (int t=0; t<T; t++) {
        
        int N;
        scanf("%d", &N);
        
        int max = -1000001, min = 1000001;
        for (int i=0; i<N; i++) {
            int num;
            scanf("%d", &num);
            if (num > max) max = num;
            if (min > num) min = num;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}