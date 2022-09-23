#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using iii = tuple<int, int, int>;

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> vShare(N), vTeam(N);
    for (int i=0; i<N; i++)
        scanf("%d", &vShare[i]);
    for (int i=0; i<N; i++) 
        scanf("%d", &vTeam[i]);
    
    vector<iii> vRe;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            vRe.push_back(make_tuple(vShare[i]*vTeam[j], vShare[i], vTeam[j]));
    }
    sort(vRe.begin(), vRe.end(), greater<>());
    
    vector<int> vDel;
    int i = 0;
    while (i < vRe.size() && vDel.size() <= K) {
        if (find(vDel.begin(), vDel.end(), get<2>(vRe[i])) == vDel.end())
            vDel.push_back(get<2>(vRe[i]));
        i++;
    }
    printf("%d", get<0>(vRe[i-1]));
    return 0;
}