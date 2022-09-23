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

int main() {

    int N;
    scanf("%d", &N);
    
    string maxp;
    int total = 0, mevol = 0;
    while (N--) {

        string p;
        cin >> p;
        int K, M;
        scanf("%d %d", &K, &M);

        int cnt = 0;
        while (M >= K) {
            cnt++;
            M -= (K-2);
        }
        
        if (cnt > mevol) {
            mevol = cnt;
            maxp = p;
        }
        total += cnt;
    }
    printf("%d\n%s", total, maxp.c_str());
    return 0;
}