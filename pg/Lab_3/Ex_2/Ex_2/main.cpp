#include <iostream>

class Animal {
    protected:
        std::string name;
        int age;

    public:
        Animal(std::string name = "Unknown", int age = 0) : name(name), age(age) {}

        void displayInfo() {
            std::cout << "name: " << name << "\n";
            std::cout << "age: " << age << "\n";
        }

        virtual void makeSound() {
            std::cout << "This general Animal class does not make any sounds. \n";
        }
};

class Dog : public Animal {
    public:
        Dog(std::string name, int age) : Animal(name, age) {}

        void makeSound() override {
            std::cout << "Woof! \n";
        }

        void displayDogInfo() {
            std::cout << "Dog name: " << name << "\n Age: " << age;
        }
};

class Cat : public Animal {
    public:
        Cat(std::string name, int age) : Animal(name, age) {}

        void makeSound() override {
            std::cout << "Meow! \n";
        }

        void displayCatInfo() {
            std::cout << "Cat name: " << name << "\n Age: " << age;
        };
};




int main() {
    Dog dog1("Pies", 10);
    dog1.displayInfo();
    dog1.makeSound();
    
    Cat cat1("Cat", 25);
    cat1.displayInfo();
    cat1.makeSound();
    

    return 0;
}
