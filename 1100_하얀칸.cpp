#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    
    string line;
    int sum;

    sum = 0;
    for (int i = 0; i < 8; i++) {
        cin >> line;

        if (i % 2 == 0) {
            for (int j = 0; j < 8; j += 2) {
                if (line[j] == 'F')
                    sum += 1;
            }
        }
        else {
            for (int j = 1; j < 8; j += 2) {
                if (line[j] == 'F')
                    sum += 1;
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}