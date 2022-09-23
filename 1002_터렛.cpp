#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for (int i=0; i < T; i++) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); //[x1, y1], [x2. y2] 사이의 거리 d
        if (x1 == x2 && y1 == y2 && r1 == r2)
            printf("-1\n");
        else if ((d > r1+r2) || (d < r1+r2) && (min(r1, r2)+d < max(r1, r2)))
            printf("0\n");
        else if ((d == r1+r2) || (d < r1+r2) && (min(r1, r2)+d == max(r1, r2)))
            printf("1\n");
        else printf("2\n");
    }
    return 0;
}