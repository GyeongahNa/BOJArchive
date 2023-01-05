#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string s;
deque<char> d1, d2;

int main() {

    cin >> s;
    for (int i=s.size()-1; i>=0; i--) {
        if (i == 0) d1.push_back(s[i]);
        else if (s[i] <= *min_element(s.begin(), s.begin()+i)) d1.push_back(s[i]);
        else d2.push_front(s[i]);
    }

    string re = "";
    while (!d1.empty()) {
        re += d1.front();
        d1.pop_front();
    }

    while (!d2.empty()) {
        re += d2.front();
        d2.pop_front();
    }
    
    cout << re;
   return 0;
}