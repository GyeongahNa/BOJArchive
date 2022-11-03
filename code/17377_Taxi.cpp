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
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iostream>

using namespace std;
using l = long long;
using ld = long double;
using ii = pair<int, int>;
using ll = pair<long, long>;

#define X first
#define Y second

ld fuel; //남은 연료
l money; //돈

int A, B, C, N, K;
l x, y, p;
string STR, G, D;

map<string, ll> coords; //좌표들
map<string, l> gas; //주유소
vector<pair<int, string>> cmd; //이동순서
string cur; //현재 위치
vector<pair<l, string>> passengers; 


void getInput() {

    cin >> A >> B >> C >> N;

    //좌표 입력
    for (int i=0; i<N; i++) {
        D = "";
        while (true) {
            string tmp;
            cin >> tmp;
            if (isdigit(tmp[0])) {
                x = stoll(tmp);
                cin >> y;
                coords[D] = {x, y};
                break;
            }
            if (D == "") D += tmp;
            else D += (" " + tmp);
        }       
    }

    //정류장 입력
    for (int i=0; i<3; i++) {
        G = "";
        while (true) {
            string tmp;
            cin >> tmp;
            if (isdigit(tmp[0])) {
                p = stoll(tmp);
                gas[G] = p;
                break;
            }
            if (G == "") G += tmp;
            else G += (" "+tmp);
        }
    }

    //명령어 입력
    cin >> K;
    for (l i=0; i<K; i++) {
        string tmp;
        cin >> tmp;
        if (tmp == "Go") {
            cin >> tmp;
            string dest = "";
            while (true) {
                cin >> tmp;
                if (dest == "") dest += tmp;
                else dest += (" "+tmp);
                if (tmp.back() == '.') break;
            }
            dest.pop_back();
            cmd.push_back({1, dest});
        }
        else {
            cin >> tmp >> tmp >> tmp >> tmp;
            string dest = "";
            while (true) {
                cin >> tmp;
                if (dest == "") dest += tmp;
                else dest += (" "+tmp);
                if (tmp.back() == '.') break;
            }
            dest.pop_back();
            cmd.push_back({2, dest});
        }
    }
}

int doCmds() {

    cur = "Taxi Garage";
    fuel = A; money = 0;

    for (auto [n, loc] : cmd) {
  
        if (n == 2) { //pickup
            passengers.push_back({0, loc});
            if (passengers.size() > 3) return 1;
            continue;
        }

        //go to
        //이동할 수 있는 남은 거리 계산
        l curx = coords[cur].X, cury = coords[cur].Y;
        l nextx = coords[loc].X, nexty = coords[loc].Y;
        int d = abs(curx-nextx) + abs(cury-nexty);
        ld used =  ld(d)/C;
        fuel -= used;
        cur = loc;
        if (fuel < -1e-12) return 0;
        
        //승객 내리기
        for (int i=0; i<passengers.size(); i++) {
            passengers[i].X += d;
            if (passengers[i].Y == loc) {
                money += passengers[i].X*B;
                passengers.erase(passengers.begin()+i);
                i--;
            }
        }

        //연료 충전하기
        if (gas.find(loc) == gas.end()) continue;
        l price = gas[loc];
        ld diff = max(A-fuel, ld(0.0));
        ld must_pay = ld(price)*diff;
        l real_pay = floor(must_pay+1e-12);

        if (money < real_pay) {
            fuel += ld(money)/price;
            fuel = min(fuel, ld(A));
            money = 0;
            continue;
        }
        money -= real_pay;
        fuel = A;
    }

    if (cur != "Taxi Garage") return 2;
    if (!passengers.empty()) return 3;
    return 4;
}

int main() {

    getInput(); 
    int ret = doCmds();
    if (ret == 0) cout<<"OUT OF GAS"<<'\n';
    else if (ret == 1) cout<<"CAPACITY FULL"<<'\n';
    else if (ret == 2) cout<<"NOT IN GARAGE"<<'\n';
    else if (ret == 3) cout<<"REMAINING PASSENGER"<<'\n';
    else cout<<money<<'\n';
    return 0;
}