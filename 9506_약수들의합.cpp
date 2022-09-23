#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    while (n != -1) {
        
        int sum = 0;
        vector<int> v;
        for (int i=1; i<n; i++) {
            if (n%i != 0) continue;
            sum += i;
            v.push_back(i);
        }
        if (sum != n) printf("%d is NOT perfect.\n", n);
        else {
            printf("%d = ", n);
            for (int i=0; i<v.size()-1; i++)
                printf("%d + ", v[i]);
            printf("%d\n", v[v.size()-1]);
        }
        scanf("%d", &n);
    }
    return 0;
}