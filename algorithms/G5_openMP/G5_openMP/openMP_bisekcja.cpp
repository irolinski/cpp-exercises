
#include <iostream>
// #include <omp.h> -- musialem podac dokladny adres
#include "/usr/local/opt/libomp/include/omp.h"


#define TABLE_SIZE 15
#define NUM_OF_QUERIES 4; 

//p jest kopia; T to oryginal
int binary_search(int *T, int p){
    //wyklad 03, str. 09
    
        int dol = 0;
        int gora = TABLE_SIZE - 1;
        int srodek;


    for(;;){
        srodek = (dol + gora) / 2;

        if (dol > gora){
            return -1;
        };
        
        
        if (T[srodek] < p) {
            dol = srodek + 1;
        };
        
        if (T[srodek] == p){
            return srodek;
            break;
        };

        if(T[srodek] > p){
            gora = srodek - 1;
        };
    };
};


void pokazWynik(int szukana, int wynik) {
    #pragma omp critical
    {
        if (wynik == -1) {
            std::cout << "Liczby " << szukana << " nie ma w tablicy. \n";
        } else {
            std::cout << "liczba " << szukana << " jest w tablicy pod indeksem: " << wynik << " \n";
        }
    }
}

void pokazThred(int szukana){
#pragma omp critical{ std::cout << "Thread numer " << omp_get_thread_num() << " zajal sie numerem " << szukana << ".\n" };
}

int main() {

    //wczytywanie szukanej wartości
    int szukana_1;
    int szukana_2;
    int szukana_3;
    int szukana_4;

    std::cout << "Podaj szukaną liczbę 1: ";
    std::cin >> szukana_1;
    std::cout << "Podaj szukaną liczbę 2: ";
    std::cin >> szukana_2;
    std::cout << "Podaj szukaną liczbę 3: ";
    std::cin >> szukana_3;
    std::cout << "Podaj szukaną liczbę 4: ";
    std::cin >> szukana_4;

    int tablicaSzukanych[4] = {szukana_1, szukana_2, szukana_3, szukana_4};
    int tablicaDanych[TABLE_SIZE] = { 1, 4, 8, 9, 10, 11, 12, 13, 14, 20, 21, 22, 30, 35, 100 };


    #pragma omp parallel for
    for (int i = 0; i < 4; i++){
        int szukana = tablicaSzukanych[i];
        int wynik = binary_search(tablicaDanych, szukana);
        pokazThred(szukana);
        pokazWynik(szukana, wynik);
    }

    return 0;
}
