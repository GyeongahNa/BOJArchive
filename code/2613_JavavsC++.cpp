#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

// 정규표현식으로도 풀어보기
bool isJava(string s) {
    
    if (s[0] < 'a' || s[0] > 'z')
        return false;
    
    for (int i=0; i < s.size(); i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z'))
            return false;
    }
    return true;
}

bool isCpp(string s) {

    if (s[0] < 'a' || s[0] > 'z')
        return false;
    
    for (int i=0; i < s.size(); i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z') && (s[i] != '_'))
            return false;
        else if (s[i] == '_' && i < s.size()-2 && s[i+1] == '_')
            return false;
        else if (i == s.size() - 1 && s[i] == '_')
            return false;
    }
    return true;
}

void convToCpp(string s) {

    for (int i=0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            printf("_%c", s[i]+32);
        else printf("%c", s[i]);
    }
    printf("\n");
}

void convToJava(string s) {
    
    for (int i=0; i < s.size(); i++) {
        if (i > 0 && s[i-1] == '_')
            printf("%c", s[i]-32);
        else if (s[i] != '_')
            printf("%c", s[i]);
    }
    printf("\n");
}

int main() {

    string s;

    getline(cin, s, '\n');
    if (isCpp(s)) {
        convToJava(s);
        return 0;
    }
    else if (isJava(s)) {
        convToCpp(s);
        return 0;
    }
    printf("Error!\n");
    return 0;
}