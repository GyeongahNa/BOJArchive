#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
using namespace std;

bool arrCmp(const int* arr1,  const int* arr2) {
    
    for (int i = 0; i < 8; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

int main() {

    int asc[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int des[8] = {8, 7 ,6, 5, 4, 3, 2, 1};
    int arr[8];

    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    
    if (arrCmp(arr, asc))
        printf("%s\n", "ascending");
    else if (arrCmp(arr, des))
        printf("%s\n", "descending");
    else
        printf("%s\n", "mixed");

    return 0;
}