#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
using ii=pair<int,int>;

void merge(ii *a, ii *tmp, int left, int right) {

    int L, R, mid, k;

    mid=(left+right)/2;
    L=left;
    R=mid+1;
    k=left;

    while (L <= mid && R <= right)
        tmp[k++]=(a[L] <= a[R] ? a[L++] : a[R++]);
    
    if (L > mid) {
        for (int i=R; i<=right; i++)
            tmp[k++]=a[i];
    }
    else {
        for (int i=L; i<=mid; i++)
            tmp[k++]=a[i];
    }

    for (int i=left; i<=right; i++)
        a[i]=tmp[i];
}

void mergeSort(ii* a, ii* tmp, int left, int right) {
    
    int mid;

    if (left==right) return;
    mid=(left+right)/2;
    mergeSort(a, tmp, left, mid);
    mergeSort(a, tmp, mid+1, right);
    merge(a, tmp, left,right);
}

//병합정렬
int main(void) {

    int N;
    scanf("%d", &N);
    ii a[N], tmp[N];

    for (int i=0; i<N; i++)
        scanf("%d %d", &(a[i].first), &(a[i].second));

    mergeSort(a, tmp, 0, N-1);
    for (int i=0; i<N; i++)
        printf("%d %d\n", a[i].first, a[i].second);

    return 0;
}

//버블정렬(시간초과)
// int main(void) {
    
//     int N;
//     scanf("%d", &N);
//     ii a[N];
//     ii tmp;

//     for (int i=0; i<N; i++)
//         scanf("%d %d", &(a[i].first), &(a[i].second));
    
//     for (int i=N-1; i>0; i--) {
//         for (int j=0; j<i; j++) {
//             if (a[j]>a[j+1]) {
//                 tmp=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=tmp;
//             }
//         }
//     }

//     for (int i=0; i<N; i++)
//         printf("%d %d\n", a[i].first, a[i].second);
//     return 0;
// }

//선택정렬(시간초과)
// int main(void) {

//     int N, minIdx;
//     ii min, tmp;
    
//     scanf("%d", &N);
//     ii a[N];
//     for (int i=0; i<N; i++)
//         scanf("%d %d", &(a[i].first), &(a[i].second));

//     for (int i=0; i<N-1; i++) {

//         min=a[i+1];
//         minIdx=i+1;
//         for (int j=i+1; j<N; j++) {
//             if (a[j]<min) {
//                 min=a[j];
//                 minIdx=j;
//             }
//         }

//         if (a[i]>min) {
//             tmp = a[i];
//             a[i]=min;
//             a[minIdx]=tmp;
//         }
//     }

//     for (int i=0; i<N; i++)
//         printf("%d %d\n", a[i].first, a[i].second);
//     return 0;
// }