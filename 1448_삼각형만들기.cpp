#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N);
    for (int i=0; i<N; i++) 
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end(), greater<>());
    for (int i=0; i<N-2; i++) {
        if (v[i+1]+v[i+2] > v[i]) {
            printf("%d\n", v[i]+v[i+1]+v[i+2]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

// 3
// 3
// 2
// 1
// output: -1

// 3
// 3
// 3
// 1
// output: 7

// 3
// 1
// 3
// 5
// output: -1

// 3
// 1
// 4
// 5
// output: -1

// 3
// 2
// 4
// 5
// output: 11

// 5
// 1
// 1000000
// 2
// 999999 
// 5
// output: 2000004