#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

bool check(int i, int f, string& s) {

    int n = f;
    while (i < s.size()) {
        n += 1;
        string ntos = to_string(n);
        string next = s.substr(i, ntos.size());
        if (ntos != next) return false;
        i += ntos.size();
    }
    printf("%d %d", f, n);
    return true;
}

int main() {

    string s;
    cin >> s;
    if (check(1, s[0]-'0', s)) return 0;
    if (check(2, stoi(s.substr(0, 2)), s)) return 0;
    if (check(3, stoi(s.substr(0, 3)), s)) return 0;
    return 0;
}