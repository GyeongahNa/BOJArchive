#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N+1);
    for (int i=1; i<=N; i++)
        scanf("%d", &v[i]);

    vector<int> vRe;
    vRe.push_back(N);

    for (int i=N-1; i>=1; i--)
        vRe.insert(vRe.begin()+v[i], i);

    for (int i=0; i<vRe.size(); i++)
        printf("%d ", vRe[i]);
    return 0;
}
