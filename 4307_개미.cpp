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
        
        int L, N;
        scanf("%d %d", &L, &N);

        int minTime = 0, maxTime = 0;
        for (int n=0; n<N; n++) {
            int pos;
            scanf("%d", &pos);
            
            int sht = min(pos, L-pos);
            int lng = max(pos, L-pos);
            minTime = max(minTime, sht);
            maxTime = max(maxTime, lng);
        }
        
        printf("%d %d\n", minTime, maxTime);
    }
    return 0;
}