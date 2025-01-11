#include <iostream>
using namespace std;

class licensePlate {
public:
    char plate[8];
    int used;

    licensePlate() {
        used = 0;
        plate[0] = 'E'; plate[1] = 'M'; plate[2] = 'P';
        plate[3] = 'T'; plate[4] = 'Y'; plate[5] = '\0';
    }

    licensePlate(char p[]) {
        used = 1;
        int i = 0;
        while (p[i] != '\0' && i < 7) {
            plate[i] = p[i];
            i++;
        }
        plate[i] = '\0'; // add null to the end
    }

    virtual void showPlate() {
        cout << "Plate: " << plate << ", Used: " << used << endl;
    }
};


licensePlate* registry[10];
int countPlates = 0;

void addPlate() {
    char temp[8];
    cout << "Enter new plate (max 7 chars): ";
    cin >> temp;

    // Create a new licensePlate and store it in the registry
    registry[countPlates] = new licensePlate(temp);
    countPlates++;
    cout << "Plate added!\n";
}

void showAll() {
    for (int i = 0; i < countPlates; i++) {
        registry[i]->showPlate(); // Use pointer to call showPlate
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

    // Clean up dynamically allocated memory
    for (int i = 0; i < countPlates; i++) {
        delete registry[i];
    }

    return 0;
}
