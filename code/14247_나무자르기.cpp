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
    for (int i=0; i<N; i++)
        scanf("%d", &v[i].second);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i].first);

    sort(v.begin(), v.end());
    long long re = 0;
    for (int i=0; i<v.size(); i++)
        re += 1LL*v[i].first*i+v[i].second;

    printf("%lld", re);
    return 0;
}