// szukanie największej sumy w wektorze metodą liniową,
// wraz z wyliczeniem indeksów podprzedziału (w05a)


#include <iostream>

//Wektor wejściowy z treści prezentacji
int wektorWejsciowy[10] = {31, -41, 59, 26, -53, 58, 97, -93 ,-23, 84};
//Program powinien zwrócić sumę x [2..6], czyli 187.

//Inne wektory na potrzeby testów
//int wektorWejsciowy[10] = {26, -53, 58, 97,31,-41, 59, -93, -23, 84};
//int wektorWejsciowy[10] = {2, 4, 5, 1, -8, 9, -10, 11, 12, 25};
//int wektorWejsciowy[10] = {2, 44, 53, -100, -8, 9, -10, 11, 12, 25};
//int wektorWejsciowy[10] = {26, -53, 58, 97, 31, -800 , -41, 59, 266, 84};

int dlugoscWektoraWejsciowego = sizeof(wektorWejsciowy)/sizeof(wektorWejsciowy[0]);

void najwSumaWektora(int *wektorWejsciowy, int dlugoscWektoraWejsciowego){
    int najwSumaPodwektora = 0;
    int sumaObecnieLiczonegoPodwektora = 0;
    int indexPoczatkuObecnieLiczonegoPodwektora = 0;
    int najwPodwektorIndexA, najwPodwektorIndexB;
    
    for (int i = 0; i < dlugoscWektoraWejsciowego; i++){
        
        //jeśli suma dotychczasowych wektorów + obecny wektor są mniejsze od 0
        if (sumaObecnieLiczonegoPodwektora + wektorWejsciowy[i] < 0){
            //zacznij "śledzić" od początku od następnej iteracji
            sumaObecnieLiczonegoPodwektora = 0;
            //i zapisz index przy którym to robisz
            indexPoczatkuObecnieLiczonegoPodwektora = i + 1;
            //jeśli suma dotychczasowych wektorów + obecny wektor są większe od 0,
        } else {
            //kontynuuj dotychczasowe "śledztwo"
            sumaObecnieLiczonegoPodwektora = sumaObecnieLiczonegoPodwektora + wektorWejsciowy[i];
        };
    
        //jeśli największy z dotychczasowo liczonych wektorów jest mniejszy lub równy od obecnie liczonego
        if (najwSumaPodwektora <= sumaObecnieLiczonegoPodwektora) {
            //zapisz, że obecnie liczony jest największy
            najwSumaPodwektora = sumaObecnieLiczonegoPodwektora;
            //i zapisz indeks kiedy to się dzieje (koniec tego podwektora)
            najwPodwektorIndexB = i;
            //i zapisz początek tego podwektora
            najwPodwektorIndexA = indexPoczatkuObecnieLiczonegoPodwektora;
        }
    };
    
    
    std::cout << "Najwieksza suma w podwektorze tego wektora to:  \n \n -------- " << najwSumaPodwektora << " -------- \n \n";
    std::cout << "Indeksy tego podprzedziału to: " << najwPodwektorIndexA << "..." << najwPodwektorIndexB << "\n \n";


};

int main() {
    
    najwSumaWektora(wektorWejsciowy, dlugoscWektoraWejsciowego);
    
    return 0;
}
