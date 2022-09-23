#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

//TC

// 2 2 
// 1 1 
// 1

// 2 2 
// 1 1
// 2

// 2 2
// 1 1
// 3

// 2 2
// 1 1
// 4

// 40000 30000
// 1 1
// 1

// 40000 30000
// 39999 29999
// 1

// 40000 30000
// 39999 29999
// 2

// 40000 40000
// 39999 39999
// 10

int main() {
    
    int w, h, p, q, T;
    scanf("%d %d\n %d %d\n %d", &w, &h, &p, &q, &T);

    if ((p+T)/w%2 == 0)
        p = (p+T)%w;
    else p = w-(p+T)%w;
    if ((q+T)/h%2 == 0)
        q = (q+T)%h;
    else q = h-(q+T)%h;
    
    printf("%d %d\n", p, q);
    return 0;
}


// 시간초과(99%)
// int main() {

//     int w, h, p, q, T;
//     scanf("%d %d\n %d %d\n %d", &w, &h, &p, &q, &T);

//     int vx = 1, vy = 1, cnt = 0;
//     while (true) {

//         int nx, ny; 
//         if (vx < 0) nx = p;
//         else nx = w-p;
//         if (vy < 0) ny = q;
//         else ny = h-q;

//         int n = min(nx, ny);
//         if (cnt + n >= T) {
//             p+=vx*(T-cnt);
//             q+=vy*(T-cnt);
//             break;
//         }
//         p+=vx*n;
//         q+=vy*n;
//         cnt+=n;
//         if (n == nx) vx*=-1;
//         if (n == ny) vy*=-1;
//     }

//     printf("%d %d", p,q);
// }


// 시간초과
// int main() {

//     int w, h, p, q, T;
//     scanf("%d %d\n %d %d\n %d", &w, &h, &p, &q, &T);

//     int vx = 1, vy = 1;
//     for (int i=0; i<T; i++) {

//         if (p+vx < 0 || p+vx > w)
//             vx*=-1;
//         if (q+vy < 0 || q+vy > h)
//             vy*=-1;
        
//         p+=vx;
//         q+=vy;
//     }
//     printf("%d %d", p, q);
//     return 0;
// }