#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int a[25], b[25];
    int sumBingo;

    for (int i = 0; i < 25; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 25; i++)
        cin >> b[i];
    
    for (int i = 0; i < 25; i++) {

        for (int j = 0; j < 25; j++) {
            if (a[j] == b[i]) a[j] = -1;
        }

        sumBingo = 0;
        for (int j = 0; j < 5; j++) {
            if (a[j*5+0] == -1 && a[j*5+1] == -1 && 
                a[j*5+2] == -1 && a[j*5+3] == -1 && a[j*5+4] == -1)
                sumBingo++;
        }

        for (int j = 0; j < 5; j++) {
            if (a[0*5+j] == -1 && a[1*5+j] == -1 && 
                a[2*5+j] == -1 && a[3*5+j] == -1 && a[4*5+j] == -1)
                sumBingo++;
        }

        if (a[0] == -1 && a[6] == -1 && 
            a[12] == -1 && a[18] == -1 && a[24] == -1)
            sumBingo++;

        if (a[4] == -1 && a[8] == -1 && 
            a[12] == -1 && a[16] == -1 && a[20] == -1)
            sumBingo++;

        if (sumBingo >= 3) {
            printf("%d\n", i+1);
            break;
        }
    }
    return 0;
}