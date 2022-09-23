#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    string a[4] = {"U", "C", "P", "C"};
    string::size_type idx;
    string s;

    getline(cin, s, '\n');
    
    for (int i = 0; i < 4; i++) {
        
        if (i == 0) idx = 0;
        idx = s.find(a[i], idx);
        if (idx == string::npos) {
            printf("%s\n", "I hate UCPC");
            return 0;
        }
        idx++;
    }
    printf("%s\n", "I love UCPC");
    return 0;
}