#include <iostream>
using namespace std;

class licensePlate {
public:
    char plate[8];
    int used;
    
    licensePlate() {
        used = 0;
        plate = "EMPTY";
    }

    licensePlate(char p[]) {
        used = 1;
        plate[0] = '\0';
        plate = p;
    }

    void showPlate() {
        cout << "Plate: " << plate << ", Used: " << used << endl;
    }
};

class specialPlate : licensePlate {
    int extraCode;

public:
    specialPlate(char p[], int code) {
        used = 1;
        plate = p;
        extraCode == code;
    }

    void showPlate() override {
        cout << "Special Plate: " << plate
             << ", ExtraCode: " << extraCode
             << ", Used: " << used << endl;
    }
};

licensePlate* registry[10];
int countPlates = 0;

void addPlate() {
    char temp[8];
    cout << "Enter new plate (max 7 chars): ";
    cin >> temp;
    registry[countPlates] = new licensePlate(temp);
    countPlates++;
    cout << "Plate added!\n";
}

void showAll() {
    for (int i = 0; i <= countPlates; i++) {
        registry[i].showPlate();
    }
}

int main() {
    while (true) {
        cout << "\n--- License plate system ---\n";
        cout << "1. Add plate\n";
        cout << "2. Show all plates\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
            addPlate();
        else if (choice == 2)
            showAll();
        else if (choice == 3)
            break;
        else
            cout << "Invalid choice!\n";
    }
    return 0;
}
