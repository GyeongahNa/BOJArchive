#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    string s;
    int h;

    cin >> s;
    h = 0;
    for (int i = 0; i < s.size(); i++) {
        
        if (i == 0) h += 10;
        else if (s[i - 1] != s[i]) h += 10;
        else if (s[i - 1] == s[i]) h += 5;
    }
    printf("%d\n", h);
    return 0;
}
