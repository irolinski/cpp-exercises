//
//  main.cpp
//  Lab_2
//
//  Created by Ignacy Roliński on 16/11/2024.
//

#include <iostream>

struct Person {
    char name[50];
    int age;
    char* city;
};


int main() {
    
    int numOfPeople;
    std::cout << "How many people do you want to do this to \n";
    std::cin >> numOfPeople;
    Person* people = new Person[numOfPeople];
    
    for (int i = 0; i< numOfPeople; i++) {
        
    }

    return 0;
}
