#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

void solve(int h, int from, int to) {
    
    if (h == 1) {
        printf("%d %d\n", from, to);
        return ;
    }

    int tmp = 6-(from+to);    
    solve(h-1, from, tmp);
    printf("%d %d\n", from, to);
    solve(h-1, tmp, to);
}

int main() {

    int N;
    scanf("%d", &N);

    string s = to_string(pow(2, N));
    s = s.substr(0, s.find('.'));
    s[s.size()-1]-=1;
    printf("%s\n", s.c_str());

    if (N <= 20) solve(N, 1, 3);
    return 0;
}
