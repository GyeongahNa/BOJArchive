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
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    int sum = 0;
    while (K--) {
        int x;
        scanf("%d", &x);
        if (x%2) sum += x/2+1;
        else sum += x/2;
    }
    
    cout << ((sum >= N) ? "YES" : "NO");
    return 0;
}