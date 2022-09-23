#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    string s;
    cin >> s;

    for (int i=s.size(); i>=0; i--) {
        if (i%2 == 1) continue;
        for (int j=0; j<=s.size()-i; j++) {
            int t1 = 0, t2 = 0;
            for (int k=j; k<j+i/2; k++) t1 += s[k];
            for (int l=j+i/2; l<j+i; l++) t2 += s[l];
            if (t1 == t2) {
                printf("%d", i);
                return 0;
            }
        }
    }
    return 0;
}