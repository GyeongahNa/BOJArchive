#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N, X;
    int arr[10000];

    cin >> N >> X;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        if (arr[i] < X)
            printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}