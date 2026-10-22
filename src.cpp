#include <iostream>
#include <cstdint>
#include <clocale>

int main(){
    std::setlocale(LC_ALL, "Russian");
    unsigned int input;
    std::cout << "Введите начальное 8-битное число (0-255): ";
    std::cin >> input;

    uint8_t initial = static_cast<uint8_t>(input);
    uint8_t current = initial;

    std::cout << "\nИсходное положение (uint8_t): " << static_cast<int>(initial) << "\n\n";

    int step_counter = 0;

    do {
        int8_t as_signed = static_cast<int8_t>(current);
        step_counter++;

        if (as_signed >= 0) {
            std::cout << "Шаг " << step_counter << ": Число " << static_cast<int>(as_signed) 
                      << " >= 0 -> Сдвиг ВПРАВО\n";
            current = (current >> 2) | (current << 6);
            
        } else {
            std::cout << "Шаг " << step_counter << ": Число " << static_cast<int>(as_signed) 
                      << " < 0 -> Сдвиг ВЛЕВО\n";
            current = (current << 2) | (current >> 6);
        }

    } while (current != initial && step_counter < 100); 

    if (current == initial) {
        std::cout << "\nЧисло успешно вернулось в исходное положение за " << step_counter << " шагов!\n";
    } else {
        std::cout << "\nЦикл прерван: число зациклилось и не может вернуться в исходное положение.\n";
    }

    return 0;
}