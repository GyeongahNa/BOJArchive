#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    
    int casen = 1;
    while (n) {
        
        int sum = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                int x;
                scanf("%d", &x);
                if (j == 1 || j == i) sum += x;
                else if (i==n) sum += x;
            }
        }
        printf("Case #%d:%d\n", casen, sum);
        scanf("%d", &n);
        casen++;
    }
    return 0;
}