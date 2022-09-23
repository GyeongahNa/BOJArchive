#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int M, N, sum;
    vector<int> v;

    cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (sqrt(i) == (int)sqrt(i))
            v.push_back(i);
    }
    
    if (v.size() == 0) {
        printf("%d\n", -1);
        return 0;
    }

    sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    printf("%d\n%d\n", sum, v[0]);
    return 0;
}