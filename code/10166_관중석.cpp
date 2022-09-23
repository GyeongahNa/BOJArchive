#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int check[2001][2001];

int gcd(int a, int b) {
    
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {

    int D1, D2;
    scanf("%d %d", &D1, &D2);
    memset(check, 0, sizeof(check));
    
    int cnt = 0;
    for (int r = D1; r <= D2; r++) {
        for (int i = 1; i <= r; i++) {
            int K = gcd(r, i);
            if (!check[i/K][r/K]) {
                check[i/K][r/K] = 1;
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}

// 벡터에 저장한 방법
// int gcd(int a, int b) {
    
//     if (b == 0) return a;
//     return gcd(b, a%b);
// }

// int main() {

//     int D1, D2;
//     scanf("%d %d", &D1, &D2);

//     vector<ii> v;
//     for (int r = D1; r <= D2; r++) {
//         for (int i = 1; i <= r; i++) {
//             int up = i / gcd(r, i);
//             int down = r / gcd(r, i);
//             v.push_back({up, down});
//         }
//     }
//     sort(v.begin(), v.end());
    
//     int cnt = 0;
//     ii last = {0, 0};
//     for (int i=0; i<v.size(); i++) {
//         if (v[i].first == last.first && v[i].second == last.second) continue;
//         last = v[i];
//         cnt++;
//     }
//     printf("%d", cnt);
//     return 0;
// }