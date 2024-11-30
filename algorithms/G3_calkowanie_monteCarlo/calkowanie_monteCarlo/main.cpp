#include <iostream>

double f(double x){
    return x * x * x;
};

double monteCarloEstimate(double a, double b, int n){
    srand(time(NULL));
    double suma = 0;
    for (int i = 1; i <= n; i++){
        //wylosuj liczbe
        double los = a + ((double)rand()/RAND_MAX * (b-a));
        //wex wartosc funkcji
        double wartoscFunkcjiOdX = f(los);
        //dodaj f(x) do sumy
        suma = suma + wartoscFunkcjiOdX;
    };
    
    double calka = (b-a) * suma / n;
    return calka;
};

int main(){
    
    double a = 1;
    double b = 2;
    int n = 1000;
    //wynik 3.75?? powinien wyjsc
    
    double wynik = monteCarloEstimate(a, b, n);
    
    std::cout << wynik;
    return 0;
};
    
