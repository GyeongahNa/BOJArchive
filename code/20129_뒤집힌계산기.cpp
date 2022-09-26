#include <cstdio>
#include <cstring>
#include <cmath>
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
using ll = long long;

#define X first
#define Y second

string o[4] = {"+", "-", "*", "/"};

vector<string> op(4, "");
deque<string> vexp;

ll operate(ll num1, ll num2, string o) {

    if (o == "+") return num1+num2;
    if (o == "-") return num1-num2;
    if (o == "*") return num1*num2;
    return num1/num2;
}

int main() {

    for (int i=0; i<4; i++) {
        int p;
        cin >> p;
        op[3-(p-1)] = o[i];  
    }

    string s;
    cin >> s;
    int sz = (int)s.size();

    for (int i=0; i<sz; i++) {
        if (s[i] < '0' || s[i] > '9') {
            vexp.push_back(string(1, s[i]));
            continue;      
        }

        string tmp = "";
        for (;i<sz && s[i] >= '0' && s[i] <= '9'; i++) tmp.push_back(s[i]);
        vexp.push_back(to_string(stoll(tmp)));
        i--;
    }

    reverse(vexp.begin(), vexp.end());

    for (auto o : op) {
        stack<string> st;
        for (auto e : vexp) {
            if (!st.empty() && st.top() == o) {
                st.pop();
                ll num1 = stoll(st.top());
                st.pop();
                ll num2 = stoll(e);
                ll res = operate(num1, num2, o);
                st.push(to_string(res));
            }
            else st.push(e);
        }

        vexp.clear();
        while (!st.empty()) {
            vexp.push_front(st.top());
            st.pop();
        }
    }

    cout<<stoll(vexp[0]);
    return 0;
}