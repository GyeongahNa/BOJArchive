#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m; //n*m , n*2m

    vector<vector<char>> v1(n, vector<char>(2*m));
    vector<vector<char>> v2(n, vector<char>(2*m));
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < 2*m; j+=2) {
            cin >> v1[i][j];
            v1[i][j+1] = v1[i][j];
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < 2*m; j++) {
            cin >> v2[i][j];
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < 2*m; j++) {
            if (v1[i][j] != v2[i][j]) {
                printf("Not Eyfa\n");
                return 0;
            }
        }
    }
    printf("Eyfa\n");
    return 0;
}