#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    if (N == 1)
        cout<<1<<endl;
    else if (N == 2)
        cout<<min((M-1)/2+1, 4)<<endl;
    else {
        if (M < 7)
            cout<<min(M, 4)<<endl;
        else cout<<M-2<<endl;
    }
    return 0;
}