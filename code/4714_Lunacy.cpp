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
    
    double n;
    scanf("%lf", &n);
    
    while (n >= 0) {
        printf("Objects weighing %.2lf on Earth ", n);
        printf("will weigh %.2lf on the moon.\n", n*0.167);
        scanf("%lf", &n);
    }
    return 0;
}