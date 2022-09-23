#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

vector<bool> getNextPoss(vector<bool> &vPass, int num) {

    vector<bool> vRe(10, true);

    vector<ii> vCheck;
    if (num == 1)
        vCheck = {{2, 3}, {4, 7}, {5, 9}};
    else if (num == 2)
        vCheck = {{5, 8}};
    else if (num == 3)
        vCheck = {{2, 1}, {5, 7}, {6, 9}};
    else if (num == 4)
        vCheck = {{5, 6}};
    else if (num == 6)
        vCheck = {{5, 4}};
    else if (num == 7)
        vCheck = {{4, 1}, {5, 3}, {8, 9}};
    else if (num == 8)
        vCheck = {{5, 2}};
    else if (num == 9)
        vCheck = {{5, 1}, {6, 3}, {8, 7}};

    for (int i=0; i<vCheck.size(); i++)
        if (!vPass[vCheck[i].first]) vRe[vCheck[i].second] = false;

    vPass[num] = true;
    for (int i=1; i<=9; i++) 
        if (vPass[i]) vRe[i] = false;
    return vRe;
}

int main() {

    int N;
    scanf("%d", &N);

    vector<bool> vPass(10), vPoss(10);
    for (int i=0; i<N; i++) {

        int n;
        scanf("%d", &n);

        if (i > 0 && !vPoss[n]) {
            printf("NO\n");
            return 0;
        } 
        vPoss = getNextPoss(vPass, n);
    }
    printf("YES\n");
    return 0;
}
