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

    int cnt=1, num=2;
    while (true) {
        int numer = 2*N - num*num + num;
        int deno = 2*num;
        if (numer <= 0) break;
        if (numer % deno == 0)
            cnt++;
        num++;
    }

    printf("%d\n", cnt);
    return 0;
}