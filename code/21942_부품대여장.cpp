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
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

long long days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long N, DDD, hh, mm, yyyy, MM, dd, L, F;
string stuff, name;
string s;

map<string, map<string, long long>> m;
map<string, long long> fine;

int main() {

    cin >> N >> s >> F;
    sscanf(s.c_str(), "%lld/%lld:%lld", &DDD, &hh, &mm);
    L = 1LL*(DDD*24*60+hh*60+mm);

    for (int i=0; i<N; i++) {
        
        cin >> s;
        sscanf(s.c_str(), "%lld-%lld-%lld", &yyyy, &MM, &dd);
        
        cin >> s;
        sscanf(s.c_str(), "%lld:%lld", &hh, &mm);
        
        cin >> stuff >> name;

        long long time = dd*24*60+hh*60+mm;
        for (int i=1; i<MM; i++) {
            time += days[i]*24*60;
        }

        if (m[name][stuff] != 0) {
            long long diff = time-m[name][stuff];
            long long pay = max(0LL, diff-L)*F;
            m[name][stuff] = 0;
            if (pay <= 0) continue;
            fine[name] += pay;
            continue;
        }
        m[name][stuff] = time;
    }
    
    vector<pair<string, long long>> v;

    for (auto [name, f] : fine) {
        v.push_back({name, f});
    }

    if (!v.size()) {
        cout << -1;
        return 0;
    }
    
    sort(v.begin(), v.end());
    for (auto [name, f] : v) {
        cout << name << " " << f << '\n';
    }
    return 0;
}