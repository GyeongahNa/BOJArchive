#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

string getFirstLast(string sBf) {

    int cnt;
    string res;

    cnt = count(sBf.begin(), sBf.end(), '\n');
    for (int i=0; i<cnt; i++) {
        string tmp = sBf.substr(i*(cnt+1), cnt);
        for (int j=0; j<3; j++) {
            res += tmp;
        }
        res += "\n";
    }
    return res;
}

string getMiddle(string sBf) {
    
    int cnt;
    string res;

    cnt = count(sBf.begin(), sBf.end(), '\n');
    for (int i=0; i<cnt; i++) {
        string tmp = sBf.substr(i*(cnt+1), cnt);
        res += tmp;
        for (int j=0; j<cnt; j++)
            res += " ";
        res += tmp;
        res += "\n";
    }
    return res;
}


string getStars(int n) {
    
    string res;

    if (n == 3)
        return "***\n* *\n***\n";
    res += getFirstLast(getStars(n/3));
    res += getMiddle(getStars(n/3));
    res += getFirstLast(getStars(n/3));
    return res;
}

int main() {
    int N;

    cin >> N;
    cout << getStars(N);
    return 0;
}
