#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {

    vector<vector<int>> v(9, vector<int>(9));
    int max, row, col;

    cin >> v[0][0];
    max = v[0][0];
    row = 1;
    col = 1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           
            if (!((i == 0) && (j == 0)))
                cin >> v[i][j];
            if (max < v[i][j]) {
                max = v[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d\n", row, col);
    return 0; 
}