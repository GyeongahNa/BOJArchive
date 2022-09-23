#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

bool isInVec(vector<char> &v, char c1) {

    char c2;

    c2 = (c1 >= 'A' && c1 <= 'Z') ? c1 + 32 : c1 - 32;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == c1 || v[i] == c2)
        return true;
    }
    return false;
}

int countChar(string &s, char c1) {

    char c2;
    int cnt;

    cnt = 0;
    c2 = (c1 >= 'A' && c1 <= 'Z') ? c1 + 32 : c1 - 32;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c1 || s[i] == c2)
            cnt++;
    }
    return cnt;
}

void printMax(vector<char> vChar, vector<int> vNum) {

    int max, maxIdx;

    max = 0;
    maxIdx = -1;
    for (int i = 0; i < vNum.size(); i++) {
        if (vNum[i] > max) {
            max = vNum[i];
            maxIdx = i;
        }
            
    }
    if (count(vNum.begin(), vNum.end(), max) > 1)
        printf("%s\n", "?");
    else
        printf("%c\n",toupper(vChar[maxIdx]));
}

int main() {

    string s;
    vector<char> vChar;
    vector<int> vNum;
    int cnt;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {

        if (!isInVec(vChar, s[i])) {
            vChar.push_back(s[i]);
            vNum.push_back(countChar(s, s[i]));
        }
    }
    printMax(vChar, vNum);
    return 0;
}