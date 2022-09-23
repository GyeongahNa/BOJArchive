#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int max, curr, x, y;

    max = 0;
    curr = 0;
    for (int i = 0; i < 10; i++) {
        cin >> x >> y;
        curr += (y - x);
        if (max < curr) max = curr; 
    }
    printf("%d\n", max);
    return 0;
}