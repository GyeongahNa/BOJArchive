#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <deque>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    deque<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    deque<int> vRe(N);
    for (int i=0; i<N; i++)
        scanf("%d", &vRe[i]);

    deque<int> vFront = vRe;
    while (vFront.front() != v.front()) {
        vFront.push_back(vFront.front());
        vFront.pop_front();
    }

    deque<int> vLast = vRe;
    while (vLast.front() != v.back()) {
        vLast.push_back(vLast.front());
        vLast.pop_front();
    } 
    reverse(vLast.begin(), vLast.end());
    
    if (vFront == v || vLast == v) printf("good puzzle\n");
    else printf("bad puzzle\n");
    return 0;
}