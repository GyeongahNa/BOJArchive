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
using ii = pair<int, int>;

int main() {

    int N;
    scanf("%d", &N);

    vector<ii> v(N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v[i].first = x;
        v[i].second = x;
    }

    for (int i=0; i<N-1; i++) {
        int x;
        scanf("%d", &x);
        v[i].second += x;
    }
    
    int re = v[0].second;
    for (int i=1; i<N; i++) {
        if (re < v[i].first) break; 
        re = max(re, v[i].second);
    }

    if (re >= v[N-1].first) printf("권병장님, 중대장님이 찾으십니다");
    else printf("엄마 나 전역 늦어질 것 같아");
    return 0;
}