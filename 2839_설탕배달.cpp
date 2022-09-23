#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int N;

    cin >> N;
    for (int i = N / 5; i >= 0; i--) {
        if ((N - 5 * i) % 3 == 0) {
            printf("%d\n", i + (N - 5 * i) / 3);
            return 0;
        }
    }
    printf("%d\n", -1);
    return 0;
}