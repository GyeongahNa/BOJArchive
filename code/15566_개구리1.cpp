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

int N, M;
int interest[20][5]; //각 개구리의 주제별 흥미도
vector<int> favor[20]; //각 자리에 올 수 있는 개구리 목록
iii tree[105]; //A, B, T
int frog[20];
int check[20];

void getInput() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> interest[i][1];
        cin >> interest[i][2];
        cin >> interest[i][3];
        cin >> interest[i][4];
    }

    for (int i=1; i<=N; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        favor[p1].push_back(i);
        favor[p2].push_back(i);
    }

    for (int i=1; i<=M; i++) {
        int A, B, T;
        cin >> A >> B >> T;
        tree[i] = {A, B, T};
    }
}

void func(int k) {

    if (k >= N+1) {
        //N개 연꽃 자리를 모두 결정했을 때 모든 통나무 대화 가능한지 확인
        for (int i=1; i<=M; i++) {
            auto [A, B, T] = tree[i];
            if (interest[frog[A]][T] != interest[frog[B]][T]) {
                return ;
            }
        }

        cout << "YES" << '\n';
        for (int i=1; i<=N; i++) {
            cout << frog[i] << " ";
        }
        exit(0);
        return ;
    }

    //k번째 자리에 올 수 있는 개구리 설정
    for (auto f : favor[k]) {
        if (check[f]) continue;
        frog[k] = f;
        check[f] = true;
        func(k+1);
        check[f] = false;
    }
}

int main() {

    getInput();
    func(1);
    cout << "NO";
    return 0;
}