#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ci = pair<char, int>;

vector<ci> parseString(const string& s) {

    vector<ci> splited;
    
    int i = 0;
    string num = "";
    while (i < s.size() && s[i] >= '0' && '9' >= s[i])
        num+=s[i++];
    splited.push_back({'+', stoi(num)});

    while (i < s.size()) {
        char sign = s[i++];
        num = "";
        while (i < s.size() && s[i] >= '0' && '9' >= s[i])
            num+=s[i++];
        splited.push_back({sign, stoi(num)});
    }
    return splited;
}

int main() {

    string s;
    cin >> s;

    vector<ci> splited = parseString(s);

    int i = 0, sum = 0;
    while (i < splited.size()) {
        
        char sign = splited[i].first;
        int num = splited[i].second;

        if (sign == '+') {
            sum+=num;
            i++;
        }
        else {
            sum-=num;
            i++;
            while (i < splited.size() && splited[i].first == '+')
                sum-=splited[i++].second;
        }
    }
    printf("%d", sum);
    return 0;
}