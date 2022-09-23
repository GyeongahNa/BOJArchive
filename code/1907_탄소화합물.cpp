#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using iii = tuple<int, int, int>;

iii getNum(const string& s) {

    int cntC = 0, cntH = 0, cntO = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
            
            int *cnt;
            if (s[i] == 'C') cnt = &cntC;
            if (s[i] == 'H') cnt = &cntH;
            else if (s[i] == 'O') cnt = &cntO;
            if (i == s.size()-1 || (i != s.size()-1 && (s[i+1] < '2' || s[i+1] > '9')))
                (*cnt)++;
            else (*cnt)+=s[i+1]-'0';
        }
    }

    iii t = make_tuple(cntC, cntH, cntO);
    return t;
}

iii operator*(const iii& t, int n) {
    
    iii tRe;
    get<0>(tRe) = get<0>(t)*n;
    get<1>(tRe) = get<1>(t)*n;
    get<2>(tRe) = get<2>(t)*n;

    return tRe;
}

iii operator+(const iii& t1, const iii& t2) {

    iii tRe;
    get<0>(tRe) = get<0>(t1)+get<0>(t2);
    get<1>(tRe) = get<1>(t1)+get<1>(t2);
    get<2>(tRe) = get<2>(t1)+get<2>(t2);

    return tRe;
}


int main() {

    string s;
    cin >> s;

    int idxP = s.find('+');
    int idxE = s.find('=');
    iii tLeft = getNum(s.substr(0, idxP));
    iii tRight = getNum(s.substr(idxP+1, idxE-idxP-1));
    iii tSum = getNum(s.substr(idxE+1));

    for (int i=1; i<=10; i++) {
        for (int j=1; j<=10; j++) {
            for (int k=1; k<=10; k++) {
                if (tLeft*i+tRight*j == tSum*k) {
                    printf("%d %d %d\n", i, j, k);
                    return 0;
                }
            }
        }
    }
    return 0;
}