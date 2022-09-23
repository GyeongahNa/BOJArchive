#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    double weight, price;
    double arr[3];

    for (int i = 0; i < 3; i++) {
        cin >> price >> weight;
        if (price >= 500)
            price -= 50;
        arr[i] = weight / price ;
    }
    
    if (arr[0] > arr[1] && arr[0] > arr[2])
        printf("S\n");
    else if (arr[1] > arr[0] && arr[1] > arr[2])
        printf("N\n");
    else
        printf("U\n");

    return 0;
}