#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    string s;
    cin >> s;

    string quack="quack";
    int qidx=0, cnt=0;
    for (int i=0; i < s.size(); i++) {
        if (s[i] == 'q') {
            int j=i;
            while (j < s.size()) {
                if (s[j] == quack[qidx])  {
                    s[j]='X';
                    qidx=(qidx+1)%5;
                }
                j++;
            }
            if (qidx != 0) break;
            cnt++;
        }
    }
    if (qidx != 0 || count(s.begin(), s.end(), 'X') != s.size())
        printf("-1\n");
    else printf("%d\n", cnt);
    return 0;
}


//시간초과
// int main() {

//     string s;
//     cin >> s;

//     int i=0, cnt=0;
//     string quack="quack";
//     while (s != "") {
//         string next="";
//         for (int j=0; j < s.size(); j++) {
//             if (s[j] == quack[i]) i=(i+1)%5;
//             else next+=s[j];
//         }
//         if (i != 0) break;
//         cnt++;
//         s=next;
//     }
//     if (i != 0) printf("-1\n");
//     else printf("%d\n", cnt);
//     return 0;
// }