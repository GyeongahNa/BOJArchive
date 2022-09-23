#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {

    int N, sum;
    int* arr;
    
    cin >> N;
    arr = new int[N];
    sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] != (i + 1))
            sum += 1;
    }

    printf("%d\n", sum);
    return 0;
}