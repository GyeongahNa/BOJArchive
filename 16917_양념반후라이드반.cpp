#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int A, B, C, X, Y;
    int common, price1, price2, sum;

    cin >> A >> B >> C >> X >> Y;
    common = (X > Y) ? Y : X;
    sum = ((A + B < 2 * C) ? A + B : 2 * C) * common;

    price1 = (X > Y) ? A * (X - common) : B * (Y - common);
    price2 = (X > Y) ?  C * 2 * (X - common) : C * 2 * (Y - common);

    sum += (price1 > price2) ? price2 : price1;
    printf("%d\n", sum);
    
    return 0;
}