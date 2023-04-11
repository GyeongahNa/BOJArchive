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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int board[3][3];
set<string> st;
string str;

bool check() {

    for (int i=0; i<3; i++) {
        bool b = true;
        for (int j=0; j<2; j++) {
            if (board[i][j] && board[i][j] == board[i][j+1]) continue;
            b = false;
            break;
        }
        if (b) return true;
    }

    for (int j=0; j<3; j++) {
        bool b = true;
        for (int i=0; i<2; i++) {
            if (board[i][j] && board[i][j] == board[i+1][j]) continue;
            b = false;
            break;
        }
        if (b) return true;
    }

    if (board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

void func(int k) {

    if (k >= 9 || check()) {
        string ret = "";
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (!board[i][j]) ret += '.';
                else if (board[i][j] == 1) ret += 'X';
                else ret += 'O';
            }
        }
        st.insert(ret);
        return ;
    }

    int person = (k%2 == 0 ? 1 : 2);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j]) continue;
            board[i][j] = person;
            func(k+1);
            board[i][j] = 0;
        }
    }
}

int main() {

    func(0);
    
    while (true) {
        cin >> str;
        if (str == "end") return 0;
        if (st.find(str) != st.end()) cout << "valid" << '\n';
        else cout << "invalid" << '\n';
    }
    return 0;
}