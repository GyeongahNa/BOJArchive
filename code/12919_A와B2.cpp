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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string S, T;

int bfs() {

    queue<string> q;
    set<string> st;

    q.push(T);
    st.insert(T);

    while (!q.empty()) {

        string front = q.front();
        if (front == S) return 1;
        q.pop();

        int sz = front.size();
        if (front.back() == 'A') {
            string new1 = front.substr(0, sz-1);
            if (st.find(new1) == st.end()){
                q.push(new1);
                st.insert(new1);
            }
        }

        if (front.front() == 'B') {
            string new2 = front;
            reverse(new2.begin(), new2.end());
            new2 = new2.substr(0, sz-1);
            if (st.find(new2) == st.end()) {
                q.push(new2);
                st.insert(new2);
            }
        }
    }
    return 0;
}    

int main() {

    cin >> S >> T;
    cout << bfs();
    return 0;
}