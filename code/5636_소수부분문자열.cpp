#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int check[100001];

int main() {
    
    memset(check, false, sizeof(check));
    
    vector<string> prime;
    for (int i=2; i<100001; i++) {
        if (check[i] == true) continue;
        prime.push_back(to_string(i));
        for (int j=i*2; j<100001; j+=i)
            check[j] = true;
    }
    
    // for (int i=0; i<10; i++) 
    //     cout<<prime[i]<<" ";
    // cout<<endl;
    
    
    string s; cin>>s;
    while (s != "0") {
        string re = "-1";
        for (int i=prime.size()-1; i>=0; i--) {
            int end = s.size() - prime[i].size();
            for (int j=0; j<=end; j++) {
                if (s.substr(j, prime[i].size()) != prime[i]) continue;
                re = prime[i];
                break;
            }
            if (re != "-1") break;
        }
        printf("%s\n", re.c_str());
        cin >> s;
    }
    return 0;
}