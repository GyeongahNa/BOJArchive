#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int searchNew(const vector<int>& v) {

    for (int i=1; i<v.size(); i++)
        if (v[i] != -1) return i;
    return v.size();
}

int cntLoop(vector<int>& v) {

    int s, cnt = 0;
    while ((s = searchNew(v)) != v.size()) {
        
        int i = s, e = v[i]; 
        v[i] = -1;
        while (s != e) {
            i = e;
            e = v[i];
            v[i] = -1;
        }
        cnt++;
    }
    return cnt;
}

int main() {

    int T;
    scanf("%d", &T);

    for (int t=0; t<T; t++) {
        int N;
        scanf("%d", &N);
        
        vector<int> v(N+1, -1);
        for (int i=1; i<=N; i++)
            scanf("%d", &v[i]);
        printf("%d\n", cntLoop(v));
    }
    return 0;
}