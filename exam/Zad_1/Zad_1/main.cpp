#include <iostream>

#define MAX_STUDENTS 100
//walidacja id dodatnie
//walidacja grade <= 6
//walidacja age <= 26
//walidacja imie 49 znakow

class Student {
private:
    int id;
    char name[50];
    int age;
    float grade;

public:
    Student() : id(0), age(0), grade(0.0f) {
        name[0] = '\0';
    }

    Student(int id, const char* nameInput, int age, float grade)
        : id(id), age(age), grade(grade) {
        int i = 0;
        while (nameInput[i] != '\0' && i < 49) {
            name[i] = nameInput[i];
            i++;
        }
        name[i] = '\0';
    }

    int getId() const {
        return id;
    }

    const char* getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    float getGrade() const {
        return grade;
    }

    void display() const {
        std::cout << "\nID: " << id << ", Name: " << name << ", Age: " << age
                  << ", Grade: " << grade << "\n";
    }
};

class StudentOperation {
public:
    virtual void execute(Student students[], int& studentCount) = 0;
    virtual ~StudentOperation() = default;
};

class AddStudent : public StudentOperation {
public:
    void execute(Student students[], int& studentCount) override {
        if (studentCount >= MAX_STUDENTS) {
            std::cout << "\nError: Maximum number of students reached!\n";
            return;
        }

        int id, age;
        float grade;
        char name[50];

        std::cout << "\nEnter the student's ID: ";
        std::cin >> id;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getId() == id) {
                std::cout << "\nError: A student with ID " << id << " already exists!\n";
                return;
            }
        }

        std::cout << "\nEnter the student's name: ";
        std::cin.ignore();
        std::cin.getline(name, 50);
        std::cout << "\nEnter the student's age: ";
        std::cin >> age;
        std::cout << "\nEnter the student's grade: ";
        std::cin >> grade;

        students[studentCount++] = Student(id, name, age, grade);
        std::cout << "\nStudent added successfully!\n";
    }
};

class DisplayStudents : public StudentOperation {
public:
    void execute(Student students[], int& studentCount) override {
        if (studentCount == 0) {
            std::cout << "\nNo students - nothing to display.\n";
            return;
        }

        for (int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }
};

class SearchStudent : public StudentOperation {
public:
    void execute(Student students[], int& studentCount) override {
        int id;
        std::cout << "Enter the ID of the student to search: ";
        std::cin >> id;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getId() == id) {
                students[i].display();
                return;
            }
        }
        std::cout << "\nStudent with ID " << id << " not found.\n";
    }
};

class DeleteStudent : public StudentOperation {
public:
    void execute(Student students[], int& studentCount) override {
        int id;
        std::cout << "\nEnter the ID of the student to delete: ";
        std::cin >> id;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getId() == id) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                std::cout << "\nStudent deleted successfully.\n";
                return;
            }
        }
        std::cout << "\nStudent with ID " << id << " not found.\n";
    }
};

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    StudentOperation* operations[4] = {
        new AddStudent(),
        new DisplayStudents(),
        new SearchStudent(),
        new DeleteStudent()
    };

    bool menuIsActive = true;

    while (menuIsActive) {
        std::cout << "\nMenu:\n"
                  << "1. Add Student\n"
                  << "2. Display All Students\n"
                  << "3. Search Student by ID\n"
                  << "4. Delete Student by ID\n"
                  << "5. Exit\n"
                  << "\nEnter your choice: ";

        int userInput;
        std::cin >> userInput;

        if (userInput >= 1 && userInput <= 4) {
            operations[userInput - 1]->execute(students, studentCount);
        } else if (userInput == 5) {
            menuIsActive = false;
        } else {
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }

    for (StudentOperation* operation : operations) {
        delete operation;
    }

    std::cout << "\nExiting the program.\n\nByeee!\n\n";
    return 0;
}
