#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string firstName;
    string middleName;
    string lastName;
    string course;
    int year;
    
    Student(int i, string fn, string mn, string ln, string c, int y) {
        id = i;
        firstName = fn;
        middleName = mn;
        lastName = ln;
        course = c;
        year = y;
    }
    
    string getFullName() {
        return firstName + " " + middleName + " " + lastName;
    }
    
    void display() {
        cout << "ID: " << id << " | Name: " << getFullName() 
             << " | Course: " << course << " | Year: " << year << endl;
    }
};

class CollegeStudentManager {
private:
    vector<Student> students;
    int nextId = 1001;
    
    vector<string> availableCourses = {
        "Computer Science",
        "Engineering",
        "Business Administration",
        "Psychology",
        "Biology",
        "Nursing",
        "Accounting",
        "Information Technology"
    };

public:
    void showCourses() {
        cout << "\n=== AVAILABLE COURSES ===" << endl;
        for (int i = 0; i < availableCourses.size(); i++) {
            cout << i + 1 << ". " << availableCourses[i] << endl;
        }
    }
    
    string selectCourse() {
        int choice;
        while (true) {
            cout << "Select course (1-" << availableCourses.size() << "): ";
            cin >> choice;
            
            if (choice >= 1 && choice <= availableCourses.size()) {
                return availableCourses[choice - 1];
            } else {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
    
    void addStudent() {
        string firstName, middleName, lastName, course;
        int year;
        
        cout << "\n=== ADD NEW STUDENT ===" << endl;
        
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter middle name: ";
        cin >> middleName;
        cout << "Enter last name: ";
        cin >> lastName;
        
        showCourses();
        course = selectCourse();
        
        cout << "Enter year (1-4): ";
        cin >> year;
        
        // Validate year
        while (year < 1 || year > 4) {
            cout << "Invalid year! Please enter 1-4: ";
            cin >> year;
        }
        
        students.push_back(Student(nextId, firstName, middleName, lastName, course, year));
        cout << "\nStudent added successfully!" << endl;
        cout << "ID: " << nextId << " | Name: " << firstName << " " << middleName << " " << lastName << endl;
        cout << "Course: " << course << " | Year: " << year << endl;
        nextId++;
    }
    
    void displayAll() {
        if (students.empty()) {
            cout << "No students in the system!" << endl;
            return;
        }
        
        cout << "\n=== ALL COLLEGE STUDENTS ===" << endl;
        for (auto &student : students) {
            student.display();
        }
        cout << "Total students: " << students.size() << endl;
    }
    
    void searchStudent() {
        if (students.empty()) {
            cout << "No students in the system!" << endl;
            return;
        }
        
        int searchId;
        cout << "Enter student ID to search: ";
        cin >> searchId;
        
        for (auto &student : students) {
            if (student.id == searchId) {
                cout << "\nStudent found:" << endl;
                student.display();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    
    void deleteStudent() {
        if (students.empty()) {
            cout << "No students in the system!" << endl;
            return;
        }
        
        int deleteId;
        cout << "Enter student ID to delete: ";
        cin >> deleteId;
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == deleteId) {
                cout << "Deleting student: ";
                students[i].display();
                students.erase(students.begin() + i);
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

void showMenu() {
    cout << "\n=== COLLEGE STUDENT MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Remove Student" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

int main() {
    CollegeStudentManager manager;
    int choice;
    
    cout << "Welcome to College Student Management System!" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.searchStudent();
                break;
            case 4:
                manager.deleteStudent();
                break;
            case 5:
                cout << "Thank you for using the College Management System!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }
    } while (choice != 5);
    
    return 0;
}