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

int N;

string toBin(int x) {

    string re = "";

    while (x) {
        re = string(1, x%2+'0') + re;
        x /= 2;
    }
    return re;
}

int main() {

    cin >> N;


    string s = toBin(N);

    cout << "s : " << s << endl;

    string ns = "";
    for (auto &e : s) {
        ns += (e == '1' ? "0" : "1");
    }

    cout << "ns : " << ns << endl;

    int nn = 0;
    for (int i=0; i<; i--) {
        if (ns[i] == '0') continue;
        cout << "i : " << i << endl;
        cout << "i-(ns.size()-1): " << i-(ns.size()-1) << endl; 
         nn += (1<<(i-(ns.size()-1)));
    }

    cout << "nn: " << nn << endl;

    if (stoi(ns) == 0) {
        cout << 1 << '\n';
        cout << N << '\n';
    }
    else {
        cout << 2 << '\n';
        cout << N << '\n';
        cout << stoi(ns) << '\n';
    }



}