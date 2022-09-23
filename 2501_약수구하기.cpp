#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N, K, num;

    cin >> N >> K;
    num = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            num += 1;
            if (num == K) {
                cout << i << endl;
                break;
            }
        }
    }

    if (num < K)
        cout << 0 << endl;
    return 0;
}
