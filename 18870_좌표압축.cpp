#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    vector<int> vsorted = v;
    sort(vsorted.begin(), vsorted.end());
    vsorted.erase(unique(vsorted.begin(), vsorted.end()), vsorted.end());
    
    for (int i=0; i<N; i++)
        printf("%ld ", lower_bound(vsorted.begin(), vsorted.end(), v[i])-vsorted.begin());
    return 0;
}