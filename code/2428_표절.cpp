#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int BinarySearch(const vector<int>& v, int i) {

    int first = i+1;
    int last = (int)v.size()-1;
    int mid;
    int re = i;

    while (first <= last) {
        mid = (first+last)/2;
        if (v[i]*10 >= v[mid]*9) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end());
    long long sum = 0;
    for (int i=0; i<N; i++) 
        sum+=BinarySearch(v, i)-i;
    printf("%lld\n", sum);
    return 0;
}