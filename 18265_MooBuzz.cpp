#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int binarySearch(int N) {

    long long first = 1;
    long long last = 2147483647;
    long long mid;

    while (first <= last) {

        mid = (first+last)/2;
        int num = mid-(mid/3+mid/5-mid/15);
        if (num == N) {
            for (int i=mid; i>=mid-2; i--)
                if (i%3 != 0 && i%5 != 0) return i;
        }
        else if (num > N) last = mid-1;
        else first = mid+1;
    }
    return -1;
}

int main() {
    
    int N;
    scanf("%d", &N);
    printf("%d", binarySearch(N));
    return 0;
}