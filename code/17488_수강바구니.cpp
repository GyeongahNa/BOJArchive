#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, M, num;
    scanf("%d %d", &N, &M);
    vector<int> v(M);
    vector<vector<int>> v_fst(N, vector<int>(0)), v_sec(N, vector<int>(0));

    for (int i=0; i<M; i++) {
        scanf("%d", &num);
        v[i]=num;
    }


    for (int i=0; i<N; i++) {
        while (true) {
            scanf("%d", &num);
            if (num==-1) break;
            v_fst[i].push_back(num);
            v[num-1]--;
        }
    }

    for (int i=0; i<M; i++) {
        if (v[i] < 0) {
            for (int j=0; j<N; j++) {
                if (find(v_fst[j].begin(), v_fst[j].end(), i+1) != v_fst[j].end())
                    v_fst[j].erase(find(v_fst[j].begin(), v_fst[j].end(), i+1));
            }
        }
    }

    for (int i=0; i<N; i++) {
        while (true) {
            scanf("%d", &num);
            if (num==-1) break;
            v_sec[i].push_back(num);
            v[num-1]--;
        }
    }

    for (int i=0; i<M; i++) {
        if (v[i] < 0) {
            for (int j=0; j<N; j++) {
                if (find(v_sec[j].begin(), v_sec[j].end(), i+1) != v_sec[j].end())
                    v_sec[j].erase(find(v_sec[j].begin(), v_sec[j].end(), i+1));
            }
        }
    }

    for (int i=0; i<N; i++) {
        
        for (int j=0; j<v_sec[i].size(); j++)
            v_fst[i].push_back(v_sec[i][j]);
        sort(v_fst[i].begin(), v_fst[i].end());

        if (v_fst[i].size() != 0) {
            for (int j=0; j<v_fst[i].size(); j++)
                printf("%d ", v_fst[i][j]);
            printf("\n");
        }
        else printf("망했어요\n");
    }

    return 0;
}