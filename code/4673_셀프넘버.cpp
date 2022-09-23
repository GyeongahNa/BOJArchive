#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    
    int isSelf;

    // 메모리 쓰라니까 5중 포문 실화냥
    // haileynam 풀이 참고
    for (int i = 1; i <= 10000; i++) {
        
        isSelf = 0;
        for (int x = 0; x <= 9; x++) {
            for (int y = 0; y <= 9; y++) {
                for (int z = 0; z <= 9; z++) {
                    for (int a = 0; a <= 9; a++) {
                        if(1001 * x + 101 * y + 11 * z + 2 * a == i)
                            isSelf = 1;
                    }
                }
            }
        }
        if (isSelf == 0)
            printf("%d\n", i);
    }
    return 0;
}