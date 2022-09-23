#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

void cntShape(vector<int>&v) {
    
    int nShape;
    scanf("%d", &nShape);
    while (nShape--) {
        int shape;
        scanf("%d", &shape);
        v[shape]++;
    }
}

int cmp(vector<int>& vA, vector<int>& vB) {
    
    int i = 4;
    while (i >= 1) {
        if (vA[i] > vB[i]) return -1;
        if (vB[i] > vA[i]) return 1;
        i--;
    }
    return 0;
}

int main() {

    int N;
    scanf("%d", &N);

    while (N--) {

        vector<int> vA(5), vB(5);
        cntShape(vA);
        cntShape(vB);
    
        int re = cmp(vA, vB);
        if (re == -1) printf("A\n");
        else if (re == 1) printf("B\n");
        else printf("D\n");
    }
    return 0;
}