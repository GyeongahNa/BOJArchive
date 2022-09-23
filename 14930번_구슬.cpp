#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ll = pair<long long, long long>;

#define pos first
#define vel second

int main() {

    int N, T;
    scanf("%d %d", &N, &T);

    vector<ll> v(N);
    for (int i=0; i<N; i++)
        scanf("%lld %lld", &v[i].pos, &v[i].vel);
    
    ll red = v[0];
    sort(v.begin(), v.end());
    int idx = find(v.begin(), v.end(), red)-v.begin();

    vector<long long> vPos(N);
    for (int i=0; i<N; i++)
        vPos[i] = v[i].pos+v[i].vel*T;
    sort(vPos.begin(), vPos.end());

    printf("%lld", vPos[idx]);
    return 0;
}