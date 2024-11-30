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
        //powiększaj lewą stronę aż znajdzie się przed środkiem
        while(tablica[i] < srodek){
            i++;
        };
        //zmniejszaj prawą stronę aż znajdzie się przed środkiem
        while(tablica[j] > srodek){
            j--;
        };
        
        //upewnij się, że i <= j zanim wykonasz kolejne operacje
        if(i <= j){
            temp = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = temp;
            i++;
            j--;
        };
    };
    
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
