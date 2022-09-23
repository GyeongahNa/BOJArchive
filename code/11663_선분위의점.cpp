#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

//STL: upper_bound(), lower_bound()로 대체 가능
int binarySearch(int start, int end, const vector<int>& v) {

    int first = 0;
    int last = (int)v.size()-1;
    int min = v.size();
    int mid;

    while (first <= last) {
        mid = (first+last)/2;
        if (v[mid] >= start) {
            min = mid;
            last = mid-1;
        }
        else first = mid+1;
    }

    first = 0; 
    last = (int)v.size()-1;
    int max = -1;

    while (first <= last) {
        mid = (first+last)/2;
        if (end >= v[mid]) {
            max = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return (max - min >= 0) ? max-min+1 : 0;
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());
    for (int i=0; i<M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
    }
    return 0;
}
