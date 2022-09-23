#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int BinarySearch(const vector<int> &v, int M) {

    int first = 1;
    int last = 1000000000;
    int mid;
    int re = 0;

    while (first <= last) {
        
        mid = (first+last)/2;
    
        long long sum = 0;
        for (int i=0; i<v.size(); i++) {
            if (v[i] <= mid) continue;
            sum+=(v[i]-mid);
        }

        if (sum >= M) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    int maxCutPoint = BinarySearch(v, M);
    printf("%d\n", maxCutPoint);
    return 0;
}