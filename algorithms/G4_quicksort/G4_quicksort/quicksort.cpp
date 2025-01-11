#include <iostream>

int tablica[10] = {5, 242, 44, 998, 997, 444, 123, 83, 123, 70};

void pokazTablice(int *array, int n)
{

    std::cout << "[";
    for (int i = 0; i < n; ++i){
        std::cout << array[i];
        i != n-1 && std::cout << ", ";
    }
    std::cout << "] \n";
}



void quicksort (int *tablica, int indexPoczatekTablicy, int indexKoniecTablicy){
    
    int i = indexPoczatekTablicy;
    int j = indexKoniecTablicy;
    int srodek = tablica[(i + j) /2]; // wyznacz środek tablicy
    int temp; // zarezerwuj miejsce na jedną liczbę do zapamiętania
    
    //dopilnuj, żeby w czasie pętli nie wyjść poza wyznaczony argumentami obszar
    while (i <= j){
        //póki liczba po lewej jest mniejsza od środka
        //dodawaj do niej 1 z każdą iteracją
        while(tablica[i] < srodek){
            i++;
        };
        //póki liczba po prawej jest większa od środka
        //odejmuj od niej 1 z każdą iteracją
        while(tablica[j] > srodek){
            j--;
        };
        
        //jeśli liczba po lewej od środka jest
        //mniejsza/równa liczbie po prawej od środka
        if(i <= j){
            // zamień je miejscami
            temp = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = temp;
            i++;
            j--;
        };
    };
    
    //wywołuj tę funkcję raz po raz póki index z
    //jednej strony nie będzie równy indexowi z drugiej strony
    
    if (j > indexPoczatekTablicy){
        quicksort(tablica, indexPoczatekTablicy, j);
    };
    if (i < indexKoniecTablicy){
        quicksort(tablica, i, indexKoniecTablicy);
    };
};

int main() {
    int dlugoscTablicy = sizeof(tablica)/sizeof(tablica[0]);
    quicksort(tablica, 0, dlugoscTablicy - 1);
    
    pokazTablice(tablica, dlugoscTablicy);
    return 0;
};
