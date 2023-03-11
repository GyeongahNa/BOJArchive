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
using iss = tuple<int, string, string>;

#define X first
#define Y second

int N, K;
string s;

struct node {
    int floor;
    string food;
    vector<node*> nexts;
};

node* head = NULL;

node* find(vector<node*> lists, string food) {

    for (node* node : lists) {
        if (node->food == food) return node;
    }
    return nullptr;
}

void getInput() {

    cin >> N;
    head = new node;

    for (int i=0; i<N; i++) {
        cin >> K;
        node* cur = head;
        for (int i=1; i<=K; i++) {
            cin >> s;
            
            node* ptr = find(cur->nexts, s);
            if (ptr) {
                cur = ptr;
                continue;
            }
    
            node* nd = new node;
            nd->floor = i;
            nd->food = s;
            cur->nexts.push_back(nd);
            cur = nd;
        }
    }
}

bool cmp(node* a, node* b) {
    return a->food < b->food;
}

void dfs(node* cur) {

    if (cur != head) {
        for (int i=0; i<(cur->floor)-1; i++) cout << "--";
        cout << cur->food << '\n';
    }
    sort(cur->nexts.begin(), cur->nexts.end(), cmp);
    for (node* next : cur->nexts) dfs(next);
}

int main() {

    getInput();
    dfs(head);
}