#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    string s;
    int cntJOI, cntIOI;

    cin >> s;
    cntJOI = 0;
    cntIOI = 0;
    for (int i = 0; i < s.size(); i++) {
        if (strcmp(s.substr(i, 3).c_str(), "JOI") == 0)
            cntJOI++;
        else if (strcmp(s.substr(i, 3).c_str(), "IOI") == 0)
            cntIOI++;
    }
    printf("%d\n%d\n", cntJOI, cntIOI);
    return 0;
}