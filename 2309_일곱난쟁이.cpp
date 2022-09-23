#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    
    vector<int> arr(9);
    int sum, v1, v2;

    sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                v1 = arr[i]; 
                v2 = arr[j]; 
            }
        }
    }
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 9; i++) {
        if (arr[i] != v1 && arr[i] != v2)
            printf("%d\n", arr[i]);
    }
    return 0;
}