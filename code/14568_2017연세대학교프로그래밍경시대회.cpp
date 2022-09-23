#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N, A, left, num;

    cin >> N;
    num  = 0;
    for (int i = 1; i <= N / 2; i++) {
        A = 2 * i;
        left = N - A;
        if (left > 3) {
            for (int diff = 2; diff < left - 1; diff++) {
                if ((left - diff) % 2 == 0)
                    num += 1;
            }
        }
    } 
    
    printf("%d\n", num);
    return 0;
}