#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N, max, min;
    int arr[1000000];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    max = arr[0];
    min = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("%d %d\n", min, max);
    return 0;
}