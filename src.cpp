#include <iostream>
#include <cstdint>
#include <bitset>

uint8_t Rotation(uint8_t current) {
    int8_t as_signed = static_cast<int8_t>(current);
    if (as_signed >= 0) {
        std::cout << "Direction: RIGHT (Value is positive or zero)\n";
        return (current >> 2) | (current << 6);
    } else {
        std::cout << "Direction: LEFT (Value is negative)\n";
        return (current << 2) | (current >> 6);
    }
}

int main() {
    int input;
    std::cout << "Enter an initial 8-bit number (-128 to 127 or 0 to 255): ";
    std::cin >> input;
    std::cout << "\n";

    uint8_t initial = static_cast<uint8_t>(input);
    std::cout << "Initial state (Binary):       " << std::bitset<8>(initial) << "\n";
    uint8_t result = Rotation(initial);
    std::cout << "Result state (Binary):        " << std::bitset<8>(result) << "\n";

    return 0;
}