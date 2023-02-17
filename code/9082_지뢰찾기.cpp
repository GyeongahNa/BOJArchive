#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N;
string s1, s2;

int main() {

    cin >> T;
    while (T--) {
        
        cin >> N >> s1 >> s2;
        vector<int> check(N, 0);

        for (int i=0; i<(int)s2.size(); i++) {
            if (s2[i] != '*') continue;
            check[i] = 1;
        }

        if (s1[0] != '0') check[0] = 1;
        if (s1[0] == '2') check[1] = 1;

        for (int i=1; i<N-1; i++) {
            int cnt = check[i-1]+check[i]+check[i+1];
            if (cnt == (s1[i]-'0')) continue;
            check[i+1] = 1; 
        }

        int re = 0;
        for (int i=0; i<N; i++)
            re += check[i];
        
        cout << re << '\n';
    }
}