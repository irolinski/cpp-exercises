

#include <iostream>

//wyklad 3 str 17



int test_losowy(int m, int n){
    
    srand(time(NULL)); //argument funkcji
    
    double wybierz = m * 1.0;
    double pozostalo = n * 1.0;
    double prawd;
    
//    pętla od i=1 do n ??
    for (int i = 1; i <= n; i++){
        // oblicz prawdopodobieństwo wylosowania i-tej liczby,
        prawd = wybierz / pozostalo;
        // wygeneruj liczbę losową los z przedziału [0,1)
        double los = (double)rand() / ((double)RAND_MAX + 1.0);
        
        if (los < prawd) {
            std::cout << i << "\n";
            wybierz = wybierz - 1;
        }
        pozostalo = pozostalo - 1;
    };
    return 0;
};


int main() {
    int m = 8; // tyle losowych liczb chce
    int n = 25; // tak dlugi jest ciag liczb
    
    test_losowy(m, n);

    return 0;
}
