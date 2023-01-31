#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n;
int board[105][105];

void getInput() {

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cin >> board[i][j];
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool bfs(int mid) {

    for (int i=0; i<=200-mid; i++) {

        queue<ii> q;
        vector<vector<bool>> visited(105, vector<bool>(105, false));
        
        if (board[0][0] >= i && board[0][0] <= i+mid) {
            q.push({0, 0});
            visited[0][0] = true;
        }

        while (!q.empty()) {

            ii cur = q.front();
            if (cur.X == n-1 && cur.Y == n-1) return true;
            q.pop();
        
            for (int k=0; k<4; k++) {
                int nx = cur.X+dx[k];
                int ny = cur.Y+dy[k];
                if (OOB(nx, ny) || visited[nx][ny]) continue;
                if (board[nx][ny] < i || board[nx][ny] > i+mid) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int binarySearch() {

    int first = 0;
    int last = 200;
    int ret = last;
    
    while (first <= last) {
        int mid = (first+last)/2;
        if (bfs(mid)) {
            ret = mid;
            last = mid-1;
        } 
        else first = mid+1;
    }

    return ret;
}

int main() {

    getInput();
    cout << binarySearch();

    return 0;
}