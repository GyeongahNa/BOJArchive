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

    if (N == 0) printf("0");
    vector<int> v;
    while (N != 0) {
        if (max(N, -N)%2 == 0) {
            v.push_back(0);
            N = (-N)/2;
        }
        else {
            v.push_back(1);
            N = (1-N)/2;
        }
    }
    for (int i=v.size()-1; i>=0; i--)
        printf("%d", v[i]);
    return 0;
}