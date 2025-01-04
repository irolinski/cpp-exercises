#include <cstdlib>
#include <iostream>

//program przyjmuje, ze w jego directory znajduja sie
//skompilowane programy oznacz i grupuj oraz plik slownik_UTF8.txt

int main() {

    const char* komenda = "./oznacz < slownik_UTF8.txt | LC_ALL=C sort | ./grupuj | awk 'NF > 1' | sort -k1 > wynik.txt";
    
    std::cout << "\n\n Upewnij sie ze uruchamiasz program za pomoca terminala \n\n";
    std::cout << "\n\n Program wymaga plikow: oznacz.exe, grupuj.exe i slownik_UTF8.txt. \n\n";

    std::cout << "Szukam anagramow:\n" << komenda << std::endl;
    
    // Execute the command
    int wynik = system(komenda);
    
    // Check if the command executed successfully
    if (wynik != 0) {
        std::cerr << "Error: Wystapil blad o kodzie: " << wynik << "." << std::endl;
        std::cout << "\n\n Sprawdz czy w folderze znajduja sie wymagane pliki, upewnij sie ze uruchamiasz program za pomoca terminala i sprobuj ponownie!";
        return 1;
    } else {
        std::cout << "Jesli nie widzisz powyzej zadnego bledu, to znaczy, ze wszystko poszlo jak z platka! \nSprawdz plik wynik.txt" << std::endl;
        return 0;
    }
}
