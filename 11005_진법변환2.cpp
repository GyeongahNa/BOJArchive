#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

char convert(int a) {
    
    if (a < 10) return a+'0';
    
    char c = 'A';
    c += (a - 10);
    return c;
}
 
int main() {
    
    int N, B;
    scanf("%d %d", &N, &B);
    
    stack<char> re;
    while (N > 0) {
        re.push(convert(N%B));
        N /= B;
    }
    
    while (!re.empty()) {
        printf("%c", re.top());
        re.pop();
    }
    
    return 0;
}