#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int convToSec(string str) {

    int h, m, s;

    h = stoi(str.substr(0, 2));
    m = stoi(str.substr(3, 2));
    s = stoi(str.substr(6, 2));

    return (h*3600 + m*60 + s);
}

string convToStr(int sec) {

    string h, m, s;

    s = to_string(sec % 60);
    m = to_string((sec / 60) % 60);
    h = to_string((sec / 60) / 60);

    s = (s.size() < 2) ? "0" + s : s;
    m = (m.size() < 2) ? "0" + m : m;
    h = (h.size() < 2) ? "0" + h : h;

    return (h + ":" + m + ":" + s);
}

int main() {

    string s1, s2;
    int curr, start;

    cin >> s1 >> s2;
    curr = convToSec(s1);
    start = convToSec(s2);

    if (start > curr)
        printf("%s\n", convToStr(start - curr).c_str());
    else
        printf("%s\n", convToStr(24*3600 - (curr - start)).c_str());
    return 0;
}