#include <iostream>
#define NUM_OF_TRIALS 1000000

int main() {
    const float line_spacing = 1.0f;  // Odleglosc miedzy liniami
    const float needle_length = 1.0f; // Dlugosc igły -- musi byc <= line_spacing
                                      // Przyjmuje, ze needle_length = line_spacing gwoli prostoty obliczen


    int crosses = 0; // Licznik przecięć

    // Inicjalizacja generatora losowego
    std::srand(std::time(nullptr));

    // Symulacja eksperymentu
    for (int i = 0; i < NUM_OF_TRIALS; ++i) {
        float randomNum_1 = std::rand() * 1.0;
        float randomNum_2 = std:: rand() * 1.0;
    
        // Losowanie środka igły (od 0 do line_spacing / 2)
        float center = randomNum_1 / RAND_MAX * (line_spacing / 2);
        // Losowanie kąta nachylenia (od 0 do pi)
        float angle = randomNum_2 / RAND_MAX * M_PI;

        // Sprawdzenie przecięcia linii
        if (center <= (needle_length / 2) * std::sin(angle)) {
            crosses++;
        }
    }

    // Obliczenie wartości π
    float pi_estimate = (2.0f * needle_length * NUM_OF_TRIALS) / (crosses * line_spacing);

    std::cout << "Liczba prob: " << NUM_OF_TRIALS << "\n";
    std::cout << "Przyblizona wartosc π: " << pi_estimate << "\n";

    return 0;
}
