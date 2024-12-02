// szukanie największej sumy w wektorze metodą liniową,
// wraz z wyliczeniem indeksów podprzedziału (w05a)


#include <iostream>

//int wektorWejsciowy[10] = {31, -41, 59, 26, -53, 58, 97, -93 ,-23, 84};
int wektorWejsciowy[10] = {2, 4, 5, 1, -8, 9, -10, 11, 12, 25};
// program powinien zwrócić sumę x [2..6], czyli 187.
int dlugoscWektoraWejsciowego = sizeof(wektorWejsciowy)/sizeof(wektorWejsciowy[0]);

void najwSumaWektora(int *wektorWejsciowy, int dlugoscWektoraWejsciowego){
    int najwDotychczas = 0;
    int najwTutaj = 0;
    int najwPodwektorIndexA, najwPodwektorIndexB;
    
    for (int i = 0; i < dlugoscWektoraWejsciowego; i++){
        najwTutaj = std::max(najwTutaj + wektorWejsciowy[i], 0);
        if (najwDotychczas <= najwTutaj) {
            najwDotychczas = najwTutaj;
            //std::cout << "Najwieksza dotychczasowa suma to: " << najwDotychczas << "\n \n";
            najwPodwektorIndexB = i;
//            najwPodwektorIndexA = dlugoscWektoraWejsciowego - 2 * i + 1;
        }
    };
    std::cout << "Najwieksza suma w podwektorze tego wektora to: " << najwDotychczas << "\n \n";
    std::cout << "Indeksy tego podprzedziału to: " << najwPodwektorIndexA << "..." << najwPodwektorIndexB << "\n \n";


};

int main() {
    
    najwSumaWektora(wektorWejsciowy, dlugoscWektoraWejsciowego);
    
    return 0;
}
