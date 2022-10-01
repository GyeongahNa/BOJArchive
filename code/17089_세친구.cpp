#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, A, B;
vector<set<int>> graph(4005);

void getInput() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B;
        graph[A].insert(B);
        graph[B].insert(A);
    }
}

int main() {

    getInput();

    int mn = 1e9;
    for (int i=1; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (graph[i].find(j) == graph[i].end()) continue;
            for (int k=j+1; k<=N; k++) {
                if (graph[k].find(i) == graph[k].end()) continue;
                if (graph[k].find(j) == graph[k].end()) continue;
                int a = (int)graph[i].size()-2;
                int b = (int)graph[j].size()-2;
                int c = (int)graph[k].size()-2;
                mn = min(mn, a+b+c);
            }
        }
    }

    if (mn == 1e9) cout<<-1;
    else cout<<mn;
    return 0;
}