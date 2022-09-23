#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int x, y, tmp;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> x >> y;
    tmp = y;
    for (int i = 0; i < x - 1; i++)
        tmp += days[i];
    
    if (tmp % 7 == 1) printf("%s\n", "MON");
    else if (tmp % 7 == 2) printf("%s\n", "TUE");
    else if (tmp % 7 == 3) printf("%s\n", "WED");
    else if (tmp % 7 == 4) printf("%s\n", "THU");
    else if (tmp % 7 == 5) printf("%s\n", "FRI");
    else if (tmp % 7 == 6) printf("%s\n", "SAT");
    else if (tmp % 7 == 0) printf("%s\n", "SUN");
    return 0;
}