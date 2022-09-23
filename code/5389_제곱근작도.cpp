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

    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {

        int n;
        scanf("%d", &n);

        vector<ii> v;
        for (int i = 1; i*i <= n; i++) {
            
            if (n%i != 0) continue;
            int diff = i;
            int sum = n/i;
            if ((sum+diff)%2 != 0) continue;
            int r = (sum+diff)/2;
            int l = r-diff;
            v.push_back({l, r});
        }

        sort(v.begin(), v.end());
        if (v.size() == 0) printf("IMPOSSIBLE\n");
        else printf("%d %d\n", v[0].first, v[0].second);
    }
    return 0;
}