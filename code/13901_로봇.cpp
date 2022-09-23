#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

void goUp(int &x, int &y, vector<vector<char>> &v) {

    while (y >= 1 && v[y-1][x] != 'X' && v[y-1][x] != 'O') {
        y--;
        v[y][x] = 'O';
    }
}

void goDown(int &x, int &y, vector<vector<char>> &v) {
    
    while (y <= v.size()-2 && v[y+1][x] != 'X' && v[y+1][x] != 'O') {
        y++;
        v[y][x] = 'O';
    }
}


void goLeft(int &x, int &y, vector<vector<char>> &v) {
    
    while (x >= 1 && v[y][x-1] != 'X' && v[y][x-1] != 'O') {
        x--;
        v[y][x] = 'O';
    }
}

void goRight(int &x, int &y, vector<vector<char>> &v) {
    
    while (x <= v[0].size()-2 && v[y][x+1] != 'X' && v[y][x+1] != 'O') {
        x++;
        v[y][x] = 'O';
    }
}

bool checkEnd(int &x, int &y, vector<vector<char>> &v) {

    if (x != 0 && v[y][x-1] != 'O' && v[y][x-1] != 'X')
        return false;
    else if (x != v[0].size() - 1 && v[y][x+1] != 'O' && v[y][x+1] != 'X')
        return false;
    else if (y != 0 && v[y-1][x] != 'O' && v[y-1][x] != 'X')
        return false;
    else if (y != v.size() - 1 && v[y+1][x] != 'O' && v[y+1][x] != 'X')
        return false;
    return true;
}

int main() {

    int w, h, nX, x, y, idx;
    cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));
    int a[4];
    
    cin >> nX;
    for (int i = 0; i < nX; i++) {
        cin >> y >> x;
        v[y][x] = 'X';
    }
    cin >> y >> x;
    v[y][x] = 'O';

    for (int i = 0; i < 4; i++)
        cin >> a[i];

    idx = 0;
    while (!checkEnd(x, y, v)) {

        if (a[idx] == 1) goUp(x, y, v);
        else if (a[idx] == 2) goDown(x, y, v);
        else if (a[idx] == 3) goLeft(x, y, v);
        else if (a[idx] == 4) goRight(x, y ,v);
        idx = (idx + 1) % 4;
    }
    printf("%d %d\n", y, x);
    return 0;
}