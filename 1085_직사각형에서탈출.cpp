#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int x, y, w, h;

    cin >> x >> y >> w >> h;
    printf("%d\n", min(min(min(h-y, y), x) , w-x));
    return 0;
}

// int main() {
//     int x, y, w, h;
//     double dist, min;

//     cin >> x >> y >> w >> h;
//     min = sqrt(w*w + h*h);
//     for (int i = 0; i <= w; i++) {
//         for (int j = 0; j <= h; j++) {
//             if (j == 0 || j == h || i == 0 || i == w) {
//                 dist = sqrt((x-i)*(x-i) + (y-j)*(y-j));
//                 if (dist < min) min = dist;
//             }
//         }
//     }
//     printf("%d\n", (int)min);
//     return 0;
// }