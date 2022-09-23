#include <iostream>
#include <string>
#include <cmath>


int main() {

    std::string hex;
    int dec;

    std::cin >> hex;
    dec = 0;
    for (int i = 0; i < hex.length(); i++) {
        if ((hex[i] >= 'A') && (hex[i] <= 'F'))
            dec += (int(hex[i]) - 55) * pow(16, hex.length() - 1 - i); 
        else
            dec += (int(hex[i]) - 48) * pow(16, hex.length() - 1 - i);
    }

    std::cout << dec << std::endl;
    return 0;
}