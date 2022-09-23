#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

bool findCoord(const vector<ii>& v, ii p) {

    int first = 0;
    int last = v.size()-1;
    int mid;

    while (first <= last) {
        mid = (first+last)/2;
        if (v[mid] == p)
            return true;
        else if (v[mid] > p)
            last = mid-1;
        else first = mid+1;
    }
    return false;
}

int main() {

    int N, w, h;
    scanf("%d %d %d", &N, &w, &h);
    
    vector<ii> v(N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &(v[i].first), &(v[i].second));
    
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i=0; i<N; i++) {

        int x = v[i].first;
        int y = v[i].second;
        
        ii p1 = {x+w, y};
        ii p2 = {x, y+h};
        ii p3 = {x+w, y+h};

        if (findCoord(v, p1) && findCoord(v, p2) && findCoord(v, p3))
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}