#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ddd = tuple<double, double, double>;

#define X first
#define Y second

vector<string> country(4);
vector<pair<string, string>> play(6);
vector<vector<double>> prob(6, vector<double>(3, 0));
map<string, double> res;


void setInput() {

    for (int i=0; i<4; i++) cin >> country[i];

    for (int i=0; i<6; i++) {
        cin >> play[i].X >> play[i].Y;
        for (int j=0; j<3; j++)
            cin >> prob[i][j];
    }
}

int main() {

    int cnt = 0;
    setInput();

    //6번 경기에 대한 모든 경우의 수(3^6)
    for (int num=0; num<729; num++) {

        double p = 1; //발생 확률
        map<string, int> score; //각 국가의 점수

        int tmp = num;
        for (int i=0; i<6; i++) {
            int c = tmp%3;
            if (c == 0) score[play[i].X] += 3;
            else if (c == 1) {
                score[play[i].X] += 1;
                score[play[i].Y] += 1;
            }
            else score[play[i].Y] += 3;
            p *= prob[i][c];
            tmp/=3;
        }
        
        //국가별 획득 점수를 내림차순으로 나열
        vector<pair<int, string>> v;
        for (auto [c, s] : score) v.push_back({s, c});
        sort(v.begin(), v.end(), greater<>());

        int nf = 0, idx = 0;
        while (idx < 4 && v[idx].X == v[0].X) { nf++; idx++; }

        //공동 1등이 2명 이상일 때
        if (nf >= 2) {
            for (int i=0; i<nf; i++) 
                res[v[i].Y] += p*2/nf;
            continue;
        }

        //1등이 한 명일 때
        res[v[0].Y] += p;
        int ns = 0;
        while (idx < 4 && v[idx].X == v[1].X) { ns++; idx++; }
        for (int i=1; i<1+ns; i++)
            res[v[i].Y] += p/ns;
    }   
    
    for (auto c : country)
        printf("%.10lf\n", res[c]);
    return 0;
}