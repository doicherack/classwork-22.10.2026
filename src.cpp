#include <iostream>
#include <cstdint>

int main(){
    unsigned int input;
    std::cout << "Enter number (0-255): ";
    std::cin >> input;

    uint8_t initial = static_cast<uint8_t>(input);
    uint8_t current = initial;

    std::cout << "\nStarting position (uint8_t): " << static_cast<int>(initial) << "\n\n";

    int step_counter = 0;

    do {
        int8_t as_signed = static_cast<int8_t>(current);
        step_counter++;

        if (as_signed >= 0) {
            std::cout << "Step " << step_counter << ": Number " << static_cast<int>(as_signed) 
                      << " >= 0 -> Step right\n";
            current = (current >> 2) | (current << 6);
            
        } else {
            std::cout << "Step " << step_counter << ": Number " << static_cast<int>(as_signed) 
                      << " < 0 -> Step left\n";
            current = (current << 2) | (current >> 6);
        }

    } while (current != initial && step_counter < 100); 

    if (current == initial) {
        std::cout << "\nThe number has successfully returned to its original position in " << step_counter << " steps!\n";
    } else {
        std::cout << "\nThe cycle has been interrupted: the number has become stuck in a loop and cannot return to its initial state.\n";
    }

    return 0;
}