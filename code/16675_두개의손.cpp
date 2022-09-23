#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int rsp(char a, char b) {

    if (a == 'S' && b == 'R')
        return -1;
    else if (a == 'S' && b == 'P')
        return 1;
    else if (a == 'R' && b == 'S')
        return 1;
    else if (a == 'R' && b == 'P')
        return -1;
    else if (a == 'P' && b == 'S')
        return -1;
    else if (a == 'P' && b == 'R')
        return 1;
    return 0;
}

int main() {

    char mL, mR, tL, tR;

    cin >> mL >> mR >> tL >> tR;
    if (mL == mR && (rsp(mL, tL) == -1 || rsp(mL, tR) == -1))
         cout << "TK" << endl;
    else if (tL == tR && (rsp(tL, mL) == -1 || rsp(tL, mR) == -1))
        cout << "MS" << endl;
    else
        cout << "?" << endl;
    return 0;
}
