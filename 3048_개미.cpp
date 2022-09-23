#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
using ci = pair<char, int>;

//TC

// 1 1
// A
// B
// 0

// 1 1
// A 
// B
// 1

// 1 1
// A 
// B
// 2

// 3 3 
// ABC
// DEF
// 50

int main() {

    int N1, N2;
    scanf("%d %d", &N1, &N2);

    string s1, s2;
    cin >> s1 >> s2;

    int T;
    scanf("%d", &T);

    vector<ci> v;
    for (int i=s1.size()-1; i>=0; i--)
        v.push_back({s1[i], 1});
    for (int i=0; i<s2.size(); i++)
        v.push_back({s2[i], 2});
    
    for (int i=0; i<T; i++) {

        vector<int> vIdx;
        for (int j=0; j<v.size()-1; j++) {
            if (v[j].second == 1 && v[j+1].second == 2)
                vIdx.push_back(j);
        }

        for (int j=0; j<vIdx.size(); j++) {
            int idx = vIdx[j];
            ci tmp = v[idx];
            v[idx] = v[idx+1];
            v[idx+1] = tmp;
        }
    }

    for (int i=0; i<v.size(); i++) 
        printf("%c", v[i].first);
    cout<<endl;
    return 0;
}