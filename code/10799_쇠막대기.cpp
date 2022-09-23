#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <stack>
using namespace std;

int main() {

    string s;
    cin >> s;

    int re = 0;   
    stack<char> st;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') st.push('(');
        else {
            st.pop();
            if (s[i-1] == '(') re+=st.size();
            else re++;
        }
    }
    printf("%d", re);
    return 0;
}

//시간초과(67%)
// int getNumStick(const string &s) {

//     int len = s.size();
//     int re = 0;

//     for (int i=0; i<len; i++) {

//         if (i >= len-1 || s[i] != '(' || s[i+1] != '(') continue;
        
//         int idx = i+1;
//         int cntLeft = 1, cntRight = 0, cntBracket = 0;  

//         while (cntLeft != cntRight) {
//             if (s[idx] == '(') {
//                 cntLeft++;
//                 if (idx < len-1 && s[idx+1] ==')')
//                     cntBracket++;
//             }
//             else cntRight++;
//             idx++;
//         }
//         re+=cntBracket+1;
//     }   
//     return re;
// }

// int main() {

//     string s;
//     cin >> s;

//     printf("%d\n", getNumStick(s));
//     return 0;
// }