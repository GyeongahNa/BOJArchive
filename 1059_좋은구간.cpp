#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int L;
    scanf("%d", &L);
    
    vector<int> v;
    v.push_back(0);
    int num;
    for (int i=0; i<L; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }

    scanf("%d", &num);
    if (find(v.begin(), v.end(), num) != v.end()) {
        printf("0\n");
        return 0;
    }

    sort(v.begin(), v.end());
    int fst, lst;
    for (int i=1; i<v.size(); i++) {
        if (num < v[i]) {
            fst=v[i-1]+1;
            lst=v[i]-1;
            break;
        }
    }

    printf("%d\n", (num-fst)*(lst-num+1)+(lst-num));
    return 0;
}