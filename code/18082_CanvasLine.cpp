#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<string> v;

bool isnum(char c) {
    return c >= '0' && c <= '9';
}

bool isalpha(char c) {
    return !isnum(c);
}

vector<string> split(const string& s) {

    vector<string> ret;
    
    for (int i=0; i<(int)s.size(); i++) {
        if (!isnum(s[i])) {
            ret.push_back(string(1, s[i]));
            continue;
        }

        string tmp = "";
        for (; i<(int)s.size() && isnum(s[i]); i++) tmp += s[i];
        ret.push_back(tmp);
        i -= 1;
    }

    return ret;
}

int cmpAlpha(const string& s1, const string& s2) {

    int idx1 = (toupper(s1[0])-'A')*2;
    int idx2 = (toupper(s2[0])-'A')*2;

    if (islower(s1[0])) idx1++;
    if (islower(s2[0])) idx2++;

    if (idx1 < idx2) return -1;
    if (idx1 > idx2) return 1;
    return 0;
}

int cmpNum(const string& n1, const string& n2) {

    int cnt1 = 0, cnt2 = 0;
    for (int i=0; i<(int)n1.size() && n1[i] == '0'; i++, cnt1++) {}
    for (int i=0; i<(int)n2.size() && n2[i] == '0'; i++, cnt2++) {}

    string sub1 = n1.substr(cnt1);
    string sub2 = n2.substr(cnt2);

    if (sub1.size() < sub2.size()) return -1;
    if (sub1.size() > sub2.size()) return 1;
    if (sub1 < sub2) return -1;
    if (sub1 > sub2) return 1;
    if (cnt1 < cnt2) return -1;
    if (cnt1 > cnt2) return 1;
    return 0;
}

bool cmp(const string& s1, const string& s2) {

    vector<string> spl1 = split(s1);
    vector<string> spl2 = split(s2);

    int sz = min((int)spl1.size(), (int)spl2.size());
    
    for (int i=0; i<sz; i++) {
        char c1 = spl1[i][0];
        char c2 = spl2[i][0];

        if (!isalpha(c1) && isalpha(c2)) return true;
        else if (isalpha(c1) && !isalpha(c2)) return false;

        int re = 0;
        if (isalpha(c1) && isalpha(c2)) 
            re = cmpAlpha(spl1[i], spl2[i]);
        else re = cmpNum(spl1[i], spl2[i]);
        if (re == -1) return true;
        else if (re == 1) return false;
    }

    if (spl1.size() < spl2.size()) return true;
    return false;
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    for (auto s : v) cout<<s<<"\n";
    return 0;
}