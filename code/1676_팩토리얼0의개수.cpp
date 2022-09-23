#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;


int main() {

    size_t N;
    scanf("%zd", &N);

    size_t total2 = 0, total5 = 0;    
    for (size_t i=2; i<=N; i++) {
        
        size_t num = i;
        size_t cnt2=0, cnt5=0;
        while (num%2 == 0 || num%5 == 0) {
            if (num%2 == 0) {
                cnt2++;
                num/=2;
            }
            else if (num%5 == 0) {
                cnt5++;
                num/=5;
            }
        }
        total2+=cnt2;
        total5+=cnt5;
    }
    printf("%lu\n", min(total2, total5));
    return 0;
}