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

int main() {
    
    int A, B;
    scanf("%d %d", &A, &B);
    
    int M;
    scanf("%d", &M);
    
    int num = 0;
    while (M--) {
        int x;
        scanf("%d", &x);
        num += x*pow(A, M);
    }
    
    stack<int> st;
    while (num > 0) {
        st.push(num%B);
        num /= B;
    }
    
    while (!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    
    return 0;
}