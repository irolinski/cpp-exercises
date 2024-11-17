#include <iostream>


//y = 3 dla x=1
//y' = 3 dla x=1
//y'' = 6 dla x=1

// Numeryczne obliczanie pochodnych
//f’(x) = [f(x+h)-f(x-h)]/(2*h)
//f’’(x) = [f(x+h)+f(x-h)-2*f(x)]/(h*h)

double y (double x) {
    int res =  x * x * x + 2;
    std::cout << "y = " << res << "\n";
    return 0;
};

double yPrim (double x) {
    int res = 3 * (x*x);
    std::cout << "y' = " << res << "\n";
    return 0;
};

double yBis(double x){
    int res =  6 * x;
    std::cout << "y'' = " << res << "\n";
    return 0;
};


int main() {
    
    int x = 5;
    
    y(x);
    yPrim(x);
    yBis(x);

    return 0;
}
