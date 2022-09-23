#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        
        int N;
        scanf("%d", &N);

        vector<int> v(N+1);
        for (int i=1; i<=N; i++)
            scanf("%d", &v[i]);

        int cnt = 1;
        int p = v[1];
        while (p != N && cnt <= N) {
            p = v[p];
            cnt++;
        }

        if (cnt > N) cnt = 0;
        printf("%d\n", cnt);
    }
    return 0;
}

//TC

// 1
// 2
// 1
// 2
// output: 0

// 2
// 2
// 1
// 2
// output: 0
// 2
// 2
// 1
// output: 1

// 1
// 10   
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// output: 0

// 1   
// 10
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 1
// output: 9

// 1
// 10
// 2
// 3
// 4
// 4
// 6
// 7
// 8
// 4
// 10
// 1
// output: 0
