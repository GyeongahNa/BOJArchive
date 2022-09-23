#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
using namespace std;

long getStart(long t) {
    
    if (t == 1) return 1;
    if (t == 2) return 2;
    return getStart(t - 1) + 6 * (t - 2);
}

long getEnd(long t) {

    if (t == 1) return 1;
    return getEnd(t - 1) + 6 * (t - 1);
}

int main() {
    long N, t;

    cin >> N;
    t = 1;
    while (true) {
        if (N >= getStart(t) && N <= getEnd(t)) {
            printf("%ld\n", t);
            break;
        }
        t++;
    }
    return 0;
}