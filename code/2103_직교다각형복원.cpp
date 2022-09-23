#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    vector<vector<int>> vX(10001);
    vector<vector<int>> vY(10001);

    for (int i=0; i<N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        vX[x].push_back(y);
        vY[y].push_back(x);
    }

    int sum = 0;
    for (int i=0; i<10001; i++) {
        sort(vX[i].begin(), vX[i].end());
        sort(vY[i].begin(), vY[i].end());

        for (int j=0; j<vX[i].size(); j+=2) 
            sum += vX[i][j+1]-vX[i][j];
        for (int j=0; j<vY[i].size(); j+=2)
            sum += vY[i][j+1]-vY[i][j];
    }

    printf("%d", sum);
    return 0;
}

//TC

// 8
// 1 1
// 4 1
// 2 2
// 4 2
// 2 3
// 4 3
// 1 4
// 4 4
// output: 16

// 8 
// 1 1
// 5 1
// 2 2
// 5 2
// 2 3
// 4 3
// 1 4
// 4 4
//output: 18

// 14
// 3 2
// 10 2
// 13 3
// 10 3
// 5 4
// 6 4
// 7 4
// 13 4
// 6 5
// 7 5
// 5 6
// 9 6
// 3 8
// 9 8
// output: 42

// 4    
// 1 10000
// 10000 1
// 10000 10000
// 1 1
// output: 39996 