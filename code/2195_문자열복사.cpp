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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string S, P;
vector<string> v;

int main() {

    cin >> S >> P;

    int cnt = 1, start = 0, end = 1;
    while (end < (int)P.size()) {
        string str = P.substr(start, end-start+1);
        if (S.find(str) != string::npos) end++;
        else {
            cnt++;
            start = end++;
        }
    }
    cout << cnt;
    return 0;
}