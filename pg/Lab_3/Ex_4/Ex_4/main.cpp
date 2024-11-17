//
//  main.cpp
//  Ex_4
//
//  Created by Ignacy Roliński on 16/11/2024.
//

#include <iostream>

class Add {
public:
    void perform(int a, int b) {
        std::cout << (a + b) << "/n";
    };
};

class Multiply {
public:
    void perform(int a, int b) {
        std::cout << (a * b) << "/n";
    };
};


int main() {
    
    std::string choice;
    std::cout << "add or multiply\n";
    std:: cin >> choice;
    
    int a, b;

    if (choice == "add") {
        Add calc;
        std::cout << "a=";
        std::cin >> a;
        std::cout << "b=";
        std::cin >> b;
        std::cout << "adding \n";
        calc.perform(a, b);

    }
    
    if (choice == "multiply"){
        Multiply calc;
        std::cout << "a=";
        std::cin >> a;
        std::cout << "b=";
        std::cin >> b;
        std::cout << "multiplying \n";
        calc.perform(a, b);
    }
    
    if (choice != "add" && choice != "multiply") {
        std::cout << "invalid choice \n";
    };

    
    return 0;
}
