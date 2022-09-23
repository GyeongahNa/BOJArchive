#include <cstring>
#include <cmath>
#include <cstdio>
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

    string s;
    char e;
    double f, re;
    for (int i=0; i<N; i++) {
        cin>>s>>e>>f;
        if (s == "H") re = -log10(f);
        else re = (14.0+log10(f));
        printf("%.2f\n", round(re*100)/100.0);
    }
    return 0;
}