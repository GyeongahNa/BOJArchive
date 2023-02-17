#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

set<vector<ii>> st;

vector<ii> normalize(const vector<ii>& shape) {

    vector<ii> newshape = shape;

    int minX = shape[0].X;
    int minY = shape[0].Y;

    for (auto& [x, y] : newshape) {
        minX = min(minX, x);
        minY = min(minY, y);
    }

    for (auto& [x, y] : newshape)  {
        x -= minX;
        y -= minY;
    }

    sort(newshape.begin(), newshape.end());
    return newshape;
}

vector<ii> flipX(const vector<ii>& shape) {

    vector<ii> flipXshape = shape;
    for (auto& [x, y] : flipXshape) {
        x = -x;
    }
    return normalize(flipXshape);
}

vector<ii> flipY(const vector<ii>& shape) {

    vector<ii> flipYshape = shape;
    for (auto& [x, y] : flipYshape) {
        y = -y;
    }

    return normalize(flipYshape);
}

vector<ii> rotate(const vector<ii>& shape) {

    vector<ii> rotateshape = shape;

    for (auto& [x, y] : rotateshape) {
        int nx = -y, ny = x;
        x = nx;
        y = ny;
    }

    return normalize(rotateshape);
}

bool duplicate(const vector<ii>& shape) {

    vector<ii> rshape = shape;
    for (int i=0; i<4; i++) {
        rshape = rotate(rshape);
        if (st.find(rshape) != st.end()) return true;
    }

    vector<ii> fXshape = flipX(shape);
    for (int i=0; i<4; i++) {
        fXshape = rotate(fXshape);
        if (st.find(fXshape) != st.end()) return true;
    }

    vector<ii> fYshape = flipY(shape);
    for (int i=0; i<4; i++) {
        fYshape = rotate(fYshape);
        if (st.find(fYshape) != st.end()) return true;
    } 

    return false;
}

void func(vector<ii> shape) {

    if ((int)shape.size() >= 8) return;

    for (auto& [x, y] : shape) {
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (find(shape.begin(), shape.end(), ii({nx, ny})) != shape.end()) continue;

            vector<ii> newshape = shape;
            newshape.emplace_back(nx, ny);
            newshape = normalize(newshape);

            if (duplicate(newshape)) continue;
            st.insert(newshape);
            func(newshape);
        }
    }
}

int main() {

    vector<ii> shape;
    shape.emplace_back(0, 0);
    func(shape);

    int cnt = 0;
    for (auto shape : st) {
        if (shape.size() == 8) cnt++;
    }

    cout << cnt;
    return 0;
}