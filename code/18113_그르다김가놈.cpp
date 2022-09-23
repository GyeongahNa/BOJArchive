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

int N, K, M;
vector<int> v;

int binarySearch() {
    
    int first = 1;
    int last = 1000000000;
    int mid;
    int re = -1;
    
    while (first <= last) {
        mid = (first+last)/2;

        int sum = 0;
        for (int i=0; i<v.size(); i++)
            sum += v[i]/mid;

        if (sum >= M) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}

int main() {
    
    scanf("%d %d %d", &N, &K, &M);
    
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        if (x >= 2*K) v.push_back(x-2*K);
        else if (x > K) v.push_back(x-K);
    }
    
    printf("%d", binarySearch());
    return 0;
}