#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    
    int N;
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {

        string s1, s2;
        cin >> s1 >> s2;
        
        vector<int> check1(27, 0);
        for (int j=0; j<s1.size(); j++)
            check1[s1[j]-'a']++;

        vector<int> check2(27, 0);
        for (int j=0; j<s2.size(); j++)
            check2[s2[j]-'a']++;

        string re = "Possible";
        for (int j=0; j<check1.size(); j++) {
            if (check1[j] == check2[j]) continue;
            re = "Impossible";
            break;
        } 
        printf("%s\n", re.c_str());
    }
    return 0;
}