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

bool pic[50][5][7];

int main() {

    int N;
    scanf("%d", &N);
    memset(pic, 0, sizeof(pic));

    for (int i=0; i<N; i++) {
        for (int j=0; j<5; j++) {
            string s;
            cin >> s;
            for (int k=0; k<7; k++)
                pic[i][j][k] = (s[k] == '.') ? 0 : 1;
        }
    }

    int maxdiff = 36, picn1 = 0, picn2 = 0;
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            int diff = 0;
            for (int k=0; k<5; k++) {
                for (int l=0; l<7; l++)
                    if (pic[i][k][l] != pic[j][k][l]) diff++;
            }
            if (diff < maxdiff) {
                picn1 = i+1;
                picn2 = j+1;
                maxdiff = diff;
            }
        }
    }

    printf("%d %d", picn1, picn2);
    return 0;
}