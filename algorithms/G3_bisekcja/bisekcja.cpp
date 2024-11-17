#include <iostream>

double f(double x);
double bisection(double a, double b, double eps);

int main() {
    //wczytanie a, b, eps

    double a, b, eps;
    std::cout << "enter a \n";
    std::cin >> a;
    std::cout << "enter b \n";
    std::cin >> b;
    std::cout << "enter eps \n";
    std::cin >> eps;

    //podstawowa kontrola danych (czy b>a)
    if (b < a) {
        std::cout << "a is larger than b; swapping places \n";
        double tmp = a;
        a = b;
        b = tmp; 
        // zamien a i b miejscami
    }
    if (eps <= 0) {
        std::cout << "Error: epsillon value invalid. It has to be larger than 0. \n";
        return 1;
    }

    //sprawdzenie czy w przedziale od a do b jest miejsce zerowe
    if (f(a) * f(b) > 0) {
        std::cout << "W przedziale nie ma miejsca zerowego \n";
        return 2; 
    }
    //wywołanie funkcji obliczającej miejsce zerowe
    double result = bisection(a, b, eps);
    // wypisanie wyniku na ekranie
    std::cout << "Miejsce zerowe jest w x =" << result << std::endl;
}

double f(double x){
    // Przykładowa funkcjal miejsce zerowe w x = 10
    return x - 10;
}

double bisection(double a, double b, double eps){
    //Funkcja oblicza (i zwraca) miejsce zerowe
    //funkcji f(x) w przedziale [a,b] z dokładnością eps
    
    double result; //zmienna na wynik obliczen

    while (b - a > eps){
        double s = (a+b) / 2.0;
        if (f(s) == 0) {
            result = s;
            break;
        }
        if (f(a) * f(s) < 0) {
            b = s;
        }
        else {
            a = s;
        }
        result = s;
    }
        return result;

}