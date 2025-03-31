#include <iostream>
#include <vector>
using namespace std;

template <typename s_ID, typename s_name, typename s_course>
class Student {
private:
    s_ID ID;
    s_name name;
    s_course course;

public:
    Student(s_ID id, s_name name, s_course course) : ID(id), name(name), course(course) {}

    void display()  {
        cout << "ID: " << ID << "  Name: " << name << "  Course: " << course << endl;
    }

    s_ID getID()  {
        return ID;
    }
};

template <typename s_ID, typename s_name, typename s_course>
class StudentDetails {
private:
    vector<Student<s_ID, s_name, s_course>> students;

public:
    void adddata(s_ID id, s_name name, s_course course) {
        students.push_back(Student<s_ID, s_name, s_course>(id, name, course));
        cout << "Student added successfully.\n";
    }


    void displayAllStudents()  {
        if (students.empty()) {
            cout << "No students to display.\n";
            return;
        }
        cout << "\nStudent List:\n";
        for (auto &student : students) {
            student.display();
        }
    }

    void removeStudentByID(s_ID id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getID() == id) {
                students.erase(it);
                cout << "Student removed successfully.\n";
                return;
            }
        }
        cout << "Student ID not found.\n";
    }

    void searchStudentByID(s_ID id)  {
        for (auto &student : students) {
            if (student.getID() == id) {
                cout << "Student Found:\n";
                student.display();
                return;
            }
        }
        cout << "Student ID not found.\n";
    }
};

int main() {
    StudentDetails<int, string, string> sd1;
    int choice, ID;
    string name, course;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> ID;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Course: ";
                cin >> course;
                sd1.adddata(ID, name, course);
                break;
            case 2:
                sd1.displayAllStudents();
                break;
            case 3:
                cout << "Enter ID to remove: ";
                cin >> ID;
                sd1.removeStudentByID(ID);
                break;
            case 4:
                cout << "Enter ID to search: ";
                cin >> ID;
                sd1.searchStudentByID(ID);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
