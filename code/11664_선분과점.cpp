#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int main() {

    double Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Az, &Bx, &By, &Bz, &Cx, &Cy, &Cz);

    double x1, x2, y1, y2, z1, z2, d1, d2;
    for (int i=0; i<10000; i++) {

        x1 = Ax+(Bx-Ax)/3.0;
        x2 = Ax+2*(Bx-Ax)/3.0;
        y1 = Ay+(By-Ay)/3.0;
        y2 = Ay+2*(By-Ay)/3.0;
        z1 = Az+(Bz-Az)/3.0;
        z2 = Az+2*(Bz-Az)/3.0;

        d1 = (x1-Cx)*(x1-Cx)+(y1-Cy)*(y1-Cy)+(z1-Cz)*(z1-Cz);
        d2 = (x2-Cx)*(x2-Cx)+(y2-Cy)*(y2-Cy)+(z2-Cz)*(z2-Cz);

        if (d1 <= d2) {
            Bx = x2; By = y2; Bz = z2;
        } 
        else {
            Ax = x1; Ay = y1; Az = z1;
        }
    }

    printf("%.10f\n", min(sqrt(d1), sqrt(d2)));
    return 0;
}

