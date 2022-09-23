#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int N, max, len;
    int arr[1001];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    max = 0;
    len = 0;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            len += arr[i + 1] - arr[i];
            if (max < len) 
                max = len;
        }
        else len = 0;
    }
    printf("%d\n", max);
    return 0;
}