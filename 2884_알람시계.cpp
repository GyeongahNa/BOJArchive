#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int H, M;

    cin >> H >> M;
    if (M < 45) {
        H -= 1;
        M += 60;

        if (H == -1)
            H = 23;
    }
    
    M -= 45;
    printf("%d %d\n", H, M);
    return 0;
}