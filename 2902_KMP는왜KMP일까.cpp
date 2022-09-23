#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
using namespace std;

int main() {

    char s[101];
    char c[101];
    int i, j;

    cin >> s;
    
    i = 0;
    j = 0;
    while (true) {
        if (s[i] == '\0')
            break;
        else if (s[i] == '-')
            i++;
        else {
            c[j] = s[i];
            j++;
            while (s[i] != '-' && s[i] != '\0')
                i++;
        }
    }
    c[j] = '\0';

    printf("%s\n", c);
    return 0;
}