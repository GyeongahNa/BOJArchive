#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

vector<int> adj[9] = {
    {1, 3}, {0, 2, 4}, {1, 5},
    {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8},
    {3, 7}, {4, 6, 8}, {5, 7}
};

int flip(int n, int k) {
    return n ^ (1 << k);
} 

int solve(int bit) {

    queue<int> q;
    q.push(bit);

    bool visit[1<<10] = {};
    visit[bit] = true;

    int dist = 0;
    while (!q.empty()) {
        
        int qs = q.size();
        while (qs--) {
            
            int cur = q.front();
            q.pop();
            
            if (cur == 0) return dist;
            for (int k=0; k<9; k++) {
                int tmp = flip(cur, k);
                for (int i=0; i<adj[k].size(); i++)
                    tmp  = flip(tmp, adj[k][i]);
                
                if (!visit[tmp]) {
                    visit[tmp] = true;
                    q.push(tmp);
                }
            }
        }
        dist++;
    }
    return 0;
}

int main() {
    
    int T;
    scanf("%d ", &T);
    while (T--) {
        int bit = 0;
        for (int i=0; i<9; i++) {

            char c;
            scanf(" %c", &c);
            bit |= (c == '*')<<i;
        }
        printf("%d\n", solve(bit));
    }
    return 0;
}

