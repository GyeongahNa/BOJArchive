#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

// 다른 풀이로 
//stringstream을 이용하여 split 하는 방법
//queue를 이용하여 front를 확인하는 방법
void splitSetence(const string& s, vector<string>& v) {

    int spIdx = -1;
    for (int j=0; j<s.size(); j++) {
        if (s[j] == ' ') {
            v.push_back(s.substr(spIdx+1, j-spIdx-1));
            spIdx = j;
        }
    }
    v.push_back(s.substr(spIdx+1));
}

int main() {

    int N;
    scanf("%d\n", &N);

    string s;
    vector<vector<string>> v(N);
    for (int i=0; i<N; i++) {
        getline(cin, s, '\n');
        splitSetence(s, v[i]);
    }

    vector<string> vListen;
    getline(cin, s, '\n');
    splitSetence(s, vListen);

    int i = 0, j = 0, idx = 0;
    while (i < N) {
        j = 0; idx = 0;
        while (j < vListen.size() && idx < v[i].size()) {
            if (vListen[j] == v[i][idx]) {
                vListen[j] = "X";
                idx++;
            }
            j++;
        }
        if (idx < v[i].size()) break;
        i++;
    }

    if (i  < N || count(vListen.begin(), vListen.end(), "X") < vListen.size())
        printf("Impossible\n");
    else printf("Possible\n");
    return 0;
}