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

    vector<vector<int>> v(100, vector<int>(100));
    for (int i=0; i<N; i++) {
        int w, h;
        scanf("%d %d", &w, &h);
        for (int j=w; j<w+10; j++) {
            for (int k=h; k<h+10; k++)
                v[k][j]=1;
        }
    }
    
    int len=0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (v[i][j] == 1 && i > 0 && v[i-1][j] == 0) len++;
            if (v[i][j] == 1 && i < 99 && v[i+1][j] == 0) len++;
            if (v[i][j] == 1 && j > 0 && v[i][j-1] == 0) len++;
            if (v[i][j] == 1 && j < 99 && v[i][j+1] == 0) len++;
            if ((v[i][j] == 1) && (i == 0 || i == 99)) len++;
            if ((v[i][j] == 1) && (j == 0 || j == 99)) len++;
        }
    }
    printf("%d\n", len);
    return 0;
 }