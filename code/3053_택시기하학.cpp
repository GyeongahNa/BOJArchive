#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double R;

    cin >> R;
    printf("%0.6f\n", R * R * M_PI);
    printf("%0.6f\n", R * R * 2);

    return 0;
}