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

int main()  {
    
    string s;
    cin >> s;
    s += " ";

    string re = "";

    int n = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'X') n++;
        else if (n%2 == 0) {
            for (int j=0; j<n/4; j++) re += "AAAA";
            for (int j=0; j<n%4/2; j++) re += "BB";
            n = 0;     
            if (s[i] == '.') re += ".";
        }
        else {
            re = "-1"; 
            break;
        }
    }
    printf("%s", re.c_str());
    return 0;
}