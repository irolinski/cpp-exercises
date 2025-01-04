#include <iostream>
#include <string>

bool jest_ascii(const char c) {
    // Zwraca true jeśli znak jest zgodny z ASCII
    return c >= 32 && c <= 126;
}

std::string oczysc_do_ascii(const std::string& line) {
    std::string wynik;
    for (size_t i = 0; i < line.length(); ++i) {
        if (jest_ascii(line[i])) {
            wynik += line[i];
        }
    }
    return wynik;
}

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::cout << oczysc_do_ascii(line) << std::endl;
    }

    return 0;
}
