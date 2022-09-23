#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    string s;
    getline(cin, s);
    
    while (s != "#") {
        
        stack<char> st;
        s += ' ';
        string re = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') st.push(s[i]);
            else {
                while (!st.empty()) {
                    re += st.top();
                    st.pop();
                }
                re += ' '; 
            }
        }
        printf("%s\n", re.c_str());
        getline(cin, s);
    }
    
    return 0;
}