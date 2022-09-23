#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, i, cnt;
    string s;

    cin >> N >> s;

    i = 0;
    cnt = 0;
    while (i < N) {
        cnt++;
        if (s[i] == 'S')
            i++;
        else if (s[i] == 'L')
            i += 2;
    }
    cnt++;
    if (N < cnt) printf("%d\n", N);
    else printf("%d\n", cnt);
    return 0;
}