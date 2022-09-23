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

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;
    while (N--) {

        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (cmd == "pop") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (cmd == "size")
            cout << q.size() << "\n";
        else if (cmd == "empty")
            cout<< q.empty() << "\n";
        else if (cmd == "front") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if (cmd == "back") {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() <<"\n";
        }
    }
}