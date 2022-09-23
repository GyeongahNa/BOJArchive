#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

int main() {

    int N;
    scanf("%d", &N);

    vector<ii> v(N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &v[i].second, &v[i].first); 
    sort(v.begin(), v.end());

    int lastEnd = 0, sum = 0;
    for (int i=0; i<N; i++) {
        if (lastEnd <= v[i].second) {
            lastEnd = v[i].first;
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}