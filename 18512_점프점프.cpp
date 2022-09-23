#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    
    int X, Y, P1, P2;
    scanf("%d %d %d %d", &X, &Y, &P1, &P2);

    for (int i=0; i<10000; i++) {
        for (int j=0; j<10000; j++) {
            if (X*i+P1 == Y*j+P2) {
                cout<<X*i+P1;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}