#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int rH, rW, gW, gH, pW, pH, cnt;
    cin >> rH >> rW >> gH >> gW >> pH >> pW;
    char a[rH][rW];
    
    cnt = 0;
    for (int i = 0; i < rH; i++) {
        for (int j = 0; j < rW; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'P')
                cnt++;
        }
            
    }

    if (cnt == pH*pW)
        printf("%d\n", 0);
    else
        printf("%d\n", 1);
    return 0;
}