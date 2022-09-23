#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

char getMaxChar(const vector<string> &v, int j) {

    vector<int> cnt(4); //[cntA, cntC, cntG, cntT]

    for (int i=0; i<v.size(); i++) { 
        if (v[i][j] == 'A') cnt[0]++;
        else if (v[i][j] == 'C') cnt[1]++;
        else if (v[i][j] == 'G') cnt[2]++;
        else cnt[3]++;
    }

    if (max({cnt[0], cnt[1], cnt[2], cnt[3]}) == cnt[0]) return 'A';
    else if (max({cnt[0], cnt[1], cnt[2], cnt[3]}) == cnt[1]) return 'C';
    else if (max({cnt[0], cnt[1], cnt[2], cnt[3]}) == cnt[2]) return 'G';
    else return 'T';
}

int main() {

    int N, M;
    scanf("%d %d ", &N, &M);

    vector<string> v(N);
    for (int i=0; i<N; i++)
        cin>>v[i];

    string s="";
    for (int i=0; i<M; i++) 
        s+=getMaxChar(v, i);

    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (v[i][j] != s[j])
                cnt++;
        }
    }

    printf("%s\n", s.c_str());
    printf("%d\n", cnt);
    return 0;
}