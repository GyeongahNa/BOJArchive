#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int max, idx, tmp;

    max = 0; 
    idx = -1;

    for (int i = 1; i <= 9; i++) {
        cin >> tmp;
        if (max < tmp) {
            max = tmp;
            idx = i;
        }
    }

    printf("%d\n%d\n", max, idx);
    return 0;
}