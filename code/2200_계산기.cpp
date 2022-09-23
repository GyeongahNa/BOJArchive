#include <cstring>
#include <cmath>
#include <cstdio>
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

    vector<int> v(N+1);
    for (int i=0; i<=N; i++) {
        int x;
        scanf("%d", &x);
        v[N-i] = x;
    }

    string s = "";
    int i = 0, n = 0;
    while (i <= N) {
        
        if (v[i] != 0) {
            int j = i-n;
            while (j > 0) {
                s = "xX" + s;
                j--;
            }
            s = "+" + to_string(v[i]) + s;
            n += i-n;
        }
        i++;
    }
    s += "=";
    printf("%d", (int)s.size()-3);
    return 0;
}
