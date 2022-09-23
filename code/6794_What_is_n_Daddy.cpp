#include <iostream>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    
    int re = 0;
    for (int i=0; i<=N/2; i++)
        if (N-i>=0 && 5>=N-i) re++;
    printf("%d", re);
    return 0;
}