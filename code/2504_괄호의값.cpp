#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <stack>
using namespace std;

bool closeBracket(stack<string>& st, char bracket) {

    string open = (bracket == ']') ? "[" : "(";
    int mult = (bracket == ']') ? 3 : 2;

    int sum = 0;
    while (!st.empty() && st.top() != "(" && st.top() != "[") {
        sum+=stoi(st.top());
        st.pop();
    }

    if (st.empty() || st.top() != open) {
        printf("0");
        return false;
    }
    st.pop();
    st.push(to_string(sum*mult));
    return true ;
}

int getAnswer(stack<string> &st) {

    int re = 0;
    while (!st.empty()) {
        if (st.top() == "(" || st.top() == "[") return 0;
        re+=stoi(st.top());
        st.pop();
    }
    return re;
}

int main() {

    string s;
    cin >> s;

    stack<string> st;
    for (int i=0; i<s.size(); i++) {

        if (s.substr(i, 2) == "()") {
            st.push("2");
            i++;
        }
        else if (s.substr(i, 2) == "[]") {
            st.push("3");
            i++;
        }
        else if (s[i] == '(') st.push("(");
        else if (s[i] == '[') st.push("[");
        else if (s[i] == ']' || s[i] == ')')
            if (!closeBracket(st, s[i])) return 0;
    }
    printf("%d", getAnswer(st));
    return 0;
}