#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {

    char s[1000001];
    int i, cnt;

    cin.getline(s, 1000001, '\n');
    
    i = 0;
    cnt = 0;
    while (true) {
        if (s[i] == ' ') i++;
        else if (s[i] != ' ' && s[i] != '\0') {
            cnt += 1;
            while (s[i] != ' ' && s[i] != '\0')
                i++;
        }
        else if (s[i] == '\0') break;
    }

    printf("%d\n", cnt);
    return 0;
}