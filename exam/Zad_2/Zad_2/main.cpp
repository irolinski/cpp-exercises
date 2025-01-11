#include <iostream>
using namespace std;

class licensePlate {
public:
    char plate[8];
    bool isUsed; // changed from int 'used' to  bool 'isUsed' for better readability
    static const int minPlateLength = 5; // added min length, to prevent user from
                                        //adding things that are not licence plates
    
    static const int maxPlateLength = 7; // stored maxLength in static const for better access and reusability

    licensePlate() {
        isUsed = false;
        plate[0] = 'E'; plate[1] = 'M'; plate[2] = 'P';
        plate[3] = 'T'; plate[4] = 'Y'; plate[5] = '\0';
    }
    // ^^ not used in main - should be removed, if it's not to be used
    

    licensePlate(char p[], bool isUsedValue = true) {
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

class specialPlate : public licensePlate {
    int extraCode;

public:
    specialPlate(char p[], int code) : licensePlate(p) {
        extraCode = code;
    }

    void showPlate() override {
        cout << "Special Plate: " << plate
             << ", ExtraCode: " << extraCode
             << ", Used: " << isUsed << endl;
    }
};

// ^^ either this class should  be removed or relevant functionality in main should be introduced

int const maxRegistrySize = 10; // replaced 'magic' 10 with a named constant
licensePlate* registry[maxRegistrySize];
int countPlates = 0;


void addPlate() {
    //Check if there is space for more plates
    if (countPlates >= 10) {
        cout << "\nRegistry is full! Cannot add more plates.\n";
        return;
    }
    
    char tempPlate[licensePlate::maxPlateLength + 1]; // + 1 to make space for null at the end
    int isUsedInput;
    bool isUsedValue;
    
    //Enter plate number
    while (true){
        cout << "\nEnter new plate (max 7 chars): ";
        cin.width(licensePlate::maxPlateLength + 1); // ensure only 7 chars will be read to prevent bugs
        cin >> tempPlate;
        cin.ignore(1000, '\n'); // clear remaining input
        
        //Check if there are enough character for the input to qualify as a plate
        int tempPlateLength = licensePlate::countCharacters(tempPlate);
        if (tempPlateLength < licensePlate::minPlateLength){
            cout << "\nPlate too short! Try again!\n";
        } else {
            break;
        }
    }
    
    //Enter isUsed status
    while (true){
        cout << "\nIs the plate currently in use? \n\n";
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


void showAll() {
    for (int i = 0; i < countPlates; i++) {
        registry[i]->showPlate();
    }
}

int main() {
    while (true) {
        int choice;

        cout << "\n--- License plate system ---\n";
        cout << "1. Add plate\n";
        cout << "2. Show all plates\n";
        cout << "3. Exit\n";
        cout << "\nChoice: ";
        cin >> choice;
        
        if (choice == 1){
            addPlate();
        } else if (choice == 2){
            showAll();
        } else if (choice == 3){
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    // Clean up allocated memory
    for (int i = 0; i < countPlates; i++) {
        delete registry[i];
    }

    return 0;
}
