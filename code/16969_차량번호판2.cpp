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

    long re = 1;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'd' && (i == 0 || s[i-1] != 'd')) re = re*10%1000000009;
        else if (s[i] == 'd' && s[i-1] == 'd') re = re*9%1000000009;
        else if (s[i] == 'c' && (i == 0 || s[i-1] != 'c')) re = re*26%1000000009;
        else re = re*25%1000000009;
    }
    printf("%ld", re);
    return 0;
}