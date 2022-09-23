#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    string s1, s2, sm, bg;
    int over, start;
    vector<int> v;

    cin >> s1 >> s2;
    sm = (s1.size() <= s2.size()) ? s1 : s2;
    bg = (s1.size() <= s2.size()) ? s2 : s1;

    over = 0;
    for (int i = 0; i < sm.size(); i++) {
        v.insert(v.begin(), (over + sm[sm.size()-1-i] + bg[bg.size()-1-i] - 2*'0') % 2);
        over = (over + sm[sm.size()-1-i] + bg[bg.size()-1-i] - 2*'0') / 2;
    }

    for (int i = bg.size() - sm.size() - 1; i >= 0; i--) {
        v.insert(v.begin(), (over + bg[i] - '0') % 2);
        over = (over + bg[i] - '0') / 2;
    }

    if (over == 1) v.insert(v.begin(), 1);

    start = v.size();
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            start = i;
            break;
        }
    }

    if (start == v.size()) {
        printf("0\n");
        return 0;
    }
    for (int i = start; i < v.size(); i++)
        printf("%d", v[i]);
    printf("\n");
    return 0;
}