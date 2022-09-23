#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int getUnits(int base, int exp) {

    int units[4];
    int res, i;
    
    units[0] = base;
    res = base * base % 10;

    i = 1;
    while (res != base) {
        units[i] = res;
        res = res * base % 10;
        i++;
    }
    return (units[(exp - 1) % i] == 0) ? 10 : units[(exp - 1) % i];
}

int main() {

    int N, a, b;
    int * res;

    cin >> N;
    res = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        res[i] = getUnits(a % 10, b); 
    }

    for (int i = 0; i < N; i++)
        printf("%d\n", res[i]);
    return 0;
}