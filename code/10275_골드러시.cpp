#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

long long arr[63];

int main() {
    
    int t;
    scanf("%d", &t);
    memset(arr, 0, sizeof(arr));

    arr[0] = 1;
    for (int i=1; i<=62; i++) 
        arr[i] = arr[i-1]*2;

    for (int i=0; i<t; i++) {
        int n; 
        long long a, b;
        scanf("%d %lld %lld", &n, &a, &b);
        
        int cut = 0;
        long long sum = 0;
        for (int j=n-1; j>=0; j--) {
            cut++;
            if (sum + arr[j] < max(a, b)) sum += arr[j];
            if (sum + arr[j] == max(a, b)) break;
        }
        printf("%d\n", cut);
    }
    return 0;
}