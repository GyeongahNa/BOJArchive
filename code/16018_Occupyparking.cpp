#include <cstdio>
#include <cmath>
#include <cstring>
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
    
    vector<char> yes(N), tod(N);
    for (int i=0; i<N; i++)
        scanf(" %c", &yes[i]);
    for (int i=0; i<N; i++)
        scanf(" %c", &tod[i]);
    
    int re = 0;
    for (int i=0; i<N; i++)
        if (yes[i] == 'C' && tod[i] == 'C') re++;
    
    printf("%d\n", re);
    return 0;
}