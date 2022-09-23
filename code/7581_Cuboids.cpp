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

    int l, w, h, v;
    scanf("%d %d %d %d", &l, &w, &h, &v);
    
    while (l != 0 || w != 0 || h != 0 || v != 0) {

        if (v == 0) v = l*w*h;
        else if (l == 0) l = v/(w*h);
        else if (w == 0) w = v/(l*h);
        else if (h == 0) h = v/(l*w);
        printf("%d %d %d %d\n", l, w, h, v);
        scanf("%d %d %d %d", &l, &w, &h, &v);
    }
    return 0;
}