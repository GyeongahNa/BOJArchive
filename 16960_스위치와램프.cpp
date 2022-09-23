#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> vSwitch(N+1);
    vector<int> vLamp(M+1);
    for (int i=1; i<=N; i++) {
        
        int non;
        scanf("%d", &non);
        for (int j=0; j<non; j++) {
            int on;
            scanf("%d", &on);
            vSwitch[i].push_back(on);
            vLamp[on]++;
        }
    }

    for (int i=1; i<=N; i++) {

        for (int j=0; j<vSwitch[i].size(); j++)
            vLamp[vSwitch[i][j]]--;

        bool isAllOn = true;
        for (int j=1; j<=M; j++)
            if (vLamp[j] < 1)  isAllOn = false;
        
        if (isAllOn == true) {
            printf("1\n");
            return 0;
        }

        for (int j=0; j<vSwitch[i].size(); j++) 
            vLamp[vSwitch[i][j]]++;
    }
    printf("0\n");
    return 0;
}


// 램프를 하나씩 킨다고 생각할 때 모두 키기 위한 최소의 개수 cnt를 구하는 방식
// int main() {

//     int N, M;
//     scanf("%d %d", &N, &M);

//     vector<vector<int>> vSwitch(N, vector<int>(0));
//     vector<int> vNumLamp(M);
//     for (int i=0; i<N; i++) {

//         int noff;
//         scanf("%d", &noff);

//         for (int j=0; j<noff; j++) {
//             int off;
//             scanf("%d", &off);
//             vSwitch[i].push_back(off-1);
//             vNumLamp[off-1]++;
//         }
//     }
    
//     int cnt = 0;
//     int minLamp = min_element(vNumLamp.begin(), vNumLamp.end())-vNumLamp.begin();
//     while (vNumLamp[minLamp] != N+1) {
        
//         int maxSwitch = -1, maxVal = -1;
//         for (int i=0; i<N; i++) {
//             if (find(vSwitch[i].begin(), vSwitch[i].end(), minLamp) == vSwitch[i].end())
//                 continue;
//             if (maxVal < (int)vSwitch[i].size())  {
//                 maxSwitch = i;
//                 maxVal = vSwitch[i].size();
//             }
//         }

//         vector<int> &vLine = vSwitch[maxSwitch];
//         for (int i=0; i<vLine.size(); i++) {
            
//             for (int j=0; j<vSwitch.size(); j++) {
//                 if (j == maxSwitch) continue;
//                 while (find(vSwitch[j].begin(), vSwitch[j].end(), vLine[i]) != vSwitch[j].end())
//                     vSwitch[j].erase(find(vSwitch[j].begin(), vSwitch[j].end(), vLine[i]));                
//             }
//             vNumLamp[vLine[i]]=N+1;
//         }
//         vSwitch[maxSwitch] = vector<int>(0);
//         minLamp = min_element(vNumLamp.begin(), vNumLamp.end())-vNumLamp.begin();
//         cnt++;
//     }
//     if (cnt <= N-1) printf("1\n");
//     else printf("0\n");
//     return 0;