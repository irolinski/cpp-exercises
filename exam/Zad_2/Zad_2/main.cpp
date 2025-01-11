#include <iostream>
using namespace std;

class licensePlate {
public:
    char plate[8];
    bool isUsed;
    static const int minPlateLength = 5;
    static const int maxPlateLength = 7;

    licensePlate() {
        isUsed = false;
        plate[0] = 'E'; plate[1] = 'M'; plate[2] = 'P';
        plate[3] = 'T'; plate[4] = 'Y'; plate[5] = '\0';
    }

    licensePlate(char p[], bool isUsedValue) {
        isUsed = isUsedValue;
        int i = 0;
        while (p[i] != '\0' && i < 7) {
            plate[i] = p[i];
            i++;
        }
        plate[i] = '\0'; // add null to the end
    }
    
    static int countCharacters(char tempPlate[]) {
        int count = 0;
        while (tempPlate[count] != '\0' && count < 8) {
            count++;
        }
        return count;
    }


    virtual void showPlate() {
        cout << "\nPlate: " << plate << ", In use: " << (isUsed ? "Yes" : "No") << endl;
    }
};


licensePlate* registry[10];
int countPlates = 0;

void addPlate() {
    char tempPlate[licensePlate::maxPlateLength + 1];
    
    int isUsedInput;
    bool isUsedValue;
    
    //Enter plate number
    while (true){
        cout << "Enter new plate (max 7 chars): ";
        cin.width(licensePlate::maxPlateLength); // ensure only 7 chars will be read to prevent bugs
        cin >> tempPlate;
        cin.ignore(1000, '\n'); // clear remaining input
        
        int tempPlateLength = licensePlate::countCharacters(tempPlate);
        
            if (tempPlateLength < licensePlate::minPlateLength){
                cout << "Plate too short! Try again!";
            } else {
                break;
            }
    }
    
    //Enter isUsed status
    while (true){
        cout << "Is the plate currently in use? \n";
        cout << "0 = false; 1 = true\n";
        cout << "Choice: ";
        cin >> isUsedInput;
        if (isUsedInput == 0){
            isUsedValue = false;
            break;
        } else if (isUsedInput == 1){
            isUsedValue = true;
            break;
        } else {
            cout << "\nIncorrect input. Try again!\n";
        }
    }
    
    //Create a new licensePlate and store it in the registry
    registry[countPlates] = new licensePlate(tempPlate, isUsedValue);
    countPlates++;
    
    cout << "\nPlate added!\n";
}

void addSpecialPlate() {
    
}

void showAll() {
    for (int i = 0; i < countPlates; i++) {
        registry[i]->showPlate();
    }
}

int main() {
    while (true) {
        cout << "\n--- License plate system ---\n";
        cout << "1. Add plate\n";
        cout << "2. Add special plate\n";
        cout << "3. Show all plates\n";
        cout << "4. Exit\n";
        cout << "\nChoice:";
        int choice;
        cin >> choice;
        if (choice == 1)
            addPlate();
        else if (choice == 2)
            addSpecialPlate();
        else if (choice == 3)
            showAll();
        else if (choice == 4)
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
