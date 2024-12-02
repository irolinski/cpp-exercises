
#include <iostream>

int wektorWejsciowy[10] = {31, -41, 59, 26, -53, 58, 97, -23, 84};
// program powinien zwrócić sumę x [2..6], czyli 187.
int dlugoscWektoraWejsciowego = sizeof(wektorWejsciowy)/sizeof(wektorWejsciowy[0]);

//Algorytm sześcienny
void najwSumaPodwektora (int *wektorWejsciowy, int dlugoscWektoraWejsciowego) {
    int najwDotychczas = 0;
    int suma;
    int najwSumaIndexA, najwSumaIndexB;
    
    for(int i = 0; i < dlugoscWektoraWejsciowego -1; i++){
        for(int j = i; j < dlugoscWektoraWejsciowego - 1; j++){
             suma = 0;
            for(int k = i; k < j; k++){
                suma += wektorWejsciowy[k];
                // std::cout << suma << " to suma wektora [" << i << "..." << j << "] \n \n";
                if (suma > najwDotychczas) {
                    najwDotychczas = suma;
                    najwSumaIndexA = i;
                    najwSumaIndexB = j - 1;
                }

             }
        }
    }
    std::cout <<"Najwyższa suma elementów dotychczas to: " << najwDotychczas << "\n znajduje się ona na indexach [" << najwSumaIndexA << "..." << najwSumaIndexB << "]" << "\n \n \n";
};


int main() {
    najwSumaPodwektora(wektorWejsciowy, dlugoscWektoraWejsciowego);
    return 0;
}
