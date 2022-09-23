#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<string>::iterator Iter;

 int main () {

    vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    string s;
    cin>>s;

    int i=0, cnt=0;
    while (i < s.size()) {
        
        Iter iterTwo = find(v.begin(), v.end(), s.substr(i, 2));
        Iter iterThr = find(v.begin(), v.end(), s.substr(i, 3));

        if (iterTwo != v.end()) i+=2;
        else if (iterThr != v.end()) i+=3;
        else i++;
        cnt++;
          
    }

    printf("%d\n", cnt);
    return 0;
 }
