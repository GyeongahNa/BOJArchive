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

    int N, K;
    deque<int> d;
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) d.push_back(i);

    int idx;
    while (K) {
        idx = min((int)d.size()-1, K);
        printf("%d ", d[idx]);
        d.erase(d.begin()+idx);
        K-=idx;
    }

    while (d.size()) {
        printf("%d ", d.front());
        d.pop_front();
    }
    return 0;
}