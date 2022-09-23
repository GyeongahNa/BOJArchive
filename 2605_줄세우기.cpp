#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int N, pick, tmp;
    int* arr;

    cin >> N;
    arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    for (int i = 0; i < N; i++) {
        cin >> pick;
        tmp = arr[i];
        for (int j = i - 1; j >= i - pick; j--) //v.erase(), v.insert()
            arr[j + 1] = arr[j];
        arr[i - pick] = tmp;
    }

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}