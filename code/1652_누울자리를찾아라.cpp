#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int N, row, col;
    char a[100][100];
    string s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++)
            a[i][j] = s[j]; 
    }

    row = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 'X' && j >= 2) {
                if (a[i][j-1] == '.' && a[i][j-2] == '.')
                    row += 1;
            }
            else if (j == N - 1 && j >= 1) {
                if (a[i][j] == '.' && a[i][j-1] == '.')
                    row += 1;
            }
        }
    }

    col = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[j][i] == 'X' && j >= 2) {
                if (a[j-1][i] == '.' && a[j-2][i] == '.')
                    col += 1;
            }
            else if (j == N - 1 && j >= 1) {
                if (a[j][i] == '.' && a[j-1][i] == '.')
                    col += 1;
            }
        }
    }

    printf("%d %d\n", row, col);
    return 0;
}