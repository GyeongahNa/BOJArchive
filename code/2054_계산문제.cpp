#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

vector<string> op = {"*", "-", "+", ""};
map<string, int> prior = {{"*", 1}, {"+", 2}, {"-", 2}};

vector<string> ans;

vector<string> tokenize(const string& exp) {

    vector<string> ret;
    string buf = "";

    for (auto x : exp) {
        if (x == '+' || x == '-' || x == '*') {
            ret.push_back(buf);
            buf.clear();
            ret.push_back(string(1, x));
        }
        else buf.push_back(x);
    }

    if (buf.size()) ret.push_back(buf);
    return ret;
}

bool check(const vector<string>& tok) {

    for (auto x : tok) {
        if (x != "0" && x[0] == '0') return false;
    }
    return true;
} 

int operate(int n1, int n2, string o) {

    if (o == "*") return n1*n2;
    if (o == "-") return n1-n2;
    return n1+n2;
}

string calc(const vector<string>& tok) {

    vector<string> ret = tok;

    for (int i=1; i<=2; i++) {
        vector<string> tmp;
        for (auto t : ret) {
            if (!tmp.empty() && prior[tmp.back()] == i) {
                string o = tmp.back();
                tmp.pop_back();
                int n1 = stoi(tmp.back());
                tmp.pop_back();
                tmp.push_back(to_string(operate(n1, stoi(t), o)));
            }
            else tmp.push_back(t);
        }
        ret = tmp;
    }
    return ret[0];
}

int main() {

    string s;
    cin >> s;

    int n = (int)s.size();
    for (int num=0; num<(1<<2*(n-1)); num++) {
        
        int tmp = num;
        string exp = "";
        for (int i=0; i<n-1; i++) {
            exp.push_back(s[i]);
            exp += op[tmp%4];
            tmp /= 4;
        }
        exp.push_back(s[n-1]);

        vector<string> tokens = tokenize(exp);
        if (!check(tokens)) continue;
        if (calc(tokens) == "2000") ans.push_back(exp);
    }

    sort(ans.begin(), ans.end());
    for (auto e : ans) cout<<e<<endl;
    return 0;
}