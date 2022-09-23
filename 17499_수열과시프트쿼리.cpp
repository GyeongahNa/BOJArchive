#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <sstream>
using namespace std;

int main() {

    int N, Q;
    scanf("%d %d", &N, &Q);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    int idx = 0;
    for (int i=0; i<Q; i++) {

        int oper;
        scanf("%d", &oper);
        if (oper == 1) {
            int pos, add;
            scanf("%d %d", &pos, &add);
            v[(idx+pos-1)%v.size()]+=add;
        }
        else if (oper == 2) {
            int s;
            scanf("%d", &s);
            idx = (idx+v.size()-s)%v.size();
        }
        else { 
            int s;
            scanf("%d", &s);
            idx = (idx+s)%v.size();
        }
    }

    for (int i=idx; i<v.size(); i++)
        printf("%d ", v[i]);
    for (int i=0; i<idx; i++)
        printf("%d ", v[i]);
    return 0;
}