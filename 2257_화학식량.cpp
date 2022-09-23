#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using iii = tuple<int, int, int>;

void checkNextAdd(const string& s, int& i, int& addTo) {

    if (i < s.size()-1 && s[i+1] >= '2' && '9' >= s[i+1])
        addTo+=s[i+1]-'0';
    else addTo++;
}

int findCloseBracket(const string& s, int& i) {

    int idx = s.find(')', i+1);
    while (idx != string::npos) {
        int cntLeft = count(s.begin()+i+1, s.begin()+idx, '(');
        int cntRight = count(s.begin()+i+1, s.begin()+idx, ')');
        if (cntLeft == cntRight)
            break;
        idx = s.find(')', idx+1);
    }
    return idx;
}

iii getStoichiometry(const string &s) {

    int cntC = 0, cntH = 0, cntO = 0;

    int i;
    for (i=0; i<s.size(); i++) {
        
        if(s[i] >= '2' && '9' >= s[i]) continue;
        else if (s[i] == 'H') checkNextAdd(s, i, cntH);
        else if (s[i] == 'C') checkNextAdd(s, i, cntC);
        else if (s[i] == 'O') checkNextAdd(s, i, cntO);
        else if (s[i] == '(') {

            int idx = findCloseBracket(s, i);
            string sUnit = s.substr(i+1, idx-i-1);
            iii t = getStoichiometry(sUnit);

            i=idx;
            int mult = 1;
            if (i < s.size()-1 && s[i+1] >= '2' && '9' >= s[i+1])
                mult = s[i+1]-'0';

            cntH+=get<0>(t)*mult;
            cntC+=get<1>(t)*mult;
            cntO+=get<2>(t)*mult;
        }
    }
    return make_tuple(cntH, cntC, cntO);
}

int main() {

    string s;
    cin >> s;
    iii re = getStoichiometry(s);

    int cntH = get<0>(re);
    int cntC = get<1>(re);
    int cntO = get<2>(re);
    printf("%d", cntH+cntC*12+cntO*16);
    return 0;   
}