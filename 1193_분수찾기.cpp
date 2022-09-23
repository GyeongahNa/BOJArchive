#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    
    int X, end, dir, idx;
    cin >> X;
    end = 0;
    dir = -1;
    for (int i = 1; i <= 10000000; i++) {
        end += i;
        dir *= -1; 
        if (X <= end) {
            idx = i;
            break;
        }
    }

    if (dir == -1)
        printf("%d/%d\n", idx  - (end - X), 1 + (end - X));
    else
        printf("%d/%d\n", 1 + (end - X), idx - (end - X));
    return 0;
}