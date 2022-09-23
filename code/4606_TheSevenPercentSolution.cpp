#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    
    string s;
    getline(cin, s);
    
    while (s != "#") {
        
        int sz = s.size();
        for (int i=0; i<sz; i++) {
            if (s[i] == ' ') printf("%%20");
            else if (s[i] == '!') printf("%%21");
            else if (s[i] == '$') printf("%%24");
            else if (s[i] == '%') printf("%%25");
            else if (s[i] == '(') printf("%%28");
            else if (s[i] == ')') printf("%%29");
            else if (s[i] == '*') printf("%%2a");
            else printf("%c", s[i]);
        }
        printf("\n");
        getline(cin, s);
    }
    
    return 0;
}