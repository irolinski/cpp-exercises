
#include <iostream>


//p jest kopia; T to oryginal
int binary_search(int *T, int p){
    //wyklad 03, str. 09
    
        int dol = 0;
        int gora = 9;
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



int main() {

    //wczytywanie szukanej wartości
    int p;
    std::cout << "Podaj szukaną liczbę: " ;
    std::cin >> p;
    
    //tablica, w której będziemy wyszkuiwać
    
    int T[10] = { 1, 4, 8, 10, 20, 21, 22, 30, 35, 100 };
    
    int result = binary_search(T, p);
    
    if (result == -1) {
        std::cout << "Szukanej liczby nie ma w tablicy. \n";
    } else {
        std::cout << "liczba " << p << " jest w tablicy pod indeksem: " << result << " \n";
    };
    


    return 0;
}
