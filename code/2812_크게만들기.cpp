#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <map>
#include <set>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
string s;
vector<int> v;
stack<int> st;

void getInput() {

    cin >> N >> K >> s;
    for (auto x : s) v.push_back(x-'0');
}

int main() {

    getInput();

    int cnt = 0, i = 0;
    for (i=0; i<N && cnt<K; i++) {
        if (st.empty() || st.top() >= v[i]) st.push(v[i]);
        else {
            st.pop();
            ++cnt;
            --i;
        }
    }

    string ret = "";
    while (!st.empty()) {
        ret = string(1, st.top()+'0') + ret;
        st.pop();
    }

    for (int j=i; j<N; j++) ret += string(1, v[j]+'0');

    cout << ret.substr(0, N-K);
    return 0;
}