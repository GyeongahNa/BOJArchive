#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

using isi=tuple<int, int, string>;

int main() {

    int N;
    scanf("%d", &N);
    
    vector<isi> v(N);
    for (int i=0; i<N; i++) {
        cin>>get<0>(v[i])>>get<2>(v[i]);
        get<1>(v[i])=i;
    }

    sort(v.begin(), v.end());
    for (int i=0; i < N; i++)
        printf("%d %s\n", get<0>(v[i]), get<2>(v[i]).c_str());
    return 0;
}