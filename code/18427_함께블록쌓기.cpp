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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string s;
int N, M, H;
vector<int> blocks[55];
int dp[55][1005];

vector<int> split(const string& s) {

    vector<int> ret;

    int idx = 0;
    while (idx < s.size()) {
        string ns = "";
        while (idx < s.size() && s[idx] != ' ') {
            ns += s[idx];
            idx++;
        }
        ret.push_back(stoi(ns));
        idx++;
    }
    return ret;
}

void getInput() {

    cin >> N >> M >> H;
    cin.ignore();

    for (int i=1; i<=N; i++) {
        getline(cin, s);
        blocks[i] = split(s); 
    }
}

void dynamic() {

    dp[1][0] = 1;
    for (auto b : blocks[1]) {
        dp[1][b] = 1;
    }

    for (int i=2; i<=N; i++) {
        for (int j=0; j<=H; j++) {
            
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int cnt = dp[i-1][j];
            for (auto b : blocks[i]) {
                if (j-b < 0) continue;
                cnt = (cnt+dp[i-1][j-b])%10007;
            }
            dp[i][j] = cnt;
        }
    }
}

int main() {

    getInput();
    dynamic();
    cout << dp[N][H];
    return 0;
}