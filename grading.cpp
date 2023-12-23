#include <iostream>
#include <algorithm>
using namespace std;

class Circular_Linked_List
{
    struct Node
    {
        int student_id;
        string name;
        int total;
        string grade;
        Node* next;

        Node() : student_id(0), total(0), next(NULL) {}
    };

    Node* head;

public:
    Circular_Linked_List() : head(NULL) {}

    bool isEmpty()
    {
        return (head == NULL);
    }

   void add_student(int student_id, string name, int total)
    {
        int numStudents;
        cout << "Enter the number of students you want to add: ";
        cin >> numStudents;

        for (int i = 0; i < numStudents; ++i)
        {
        

            cout << "\nEnter details for Student " << i + 1 << ":\n";
            cout << "Enter Student ID: ";
            cin >> student_id;
            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter Student Total: ";
            cin >> total;
           
             Node* new_student = new Node;
            new_student->student_id = student_id;
            new_student->name = name;
            new_student->total = total;
            assignGrade(new_student);
        if (isEmpty())
            {
                head = new_student;
                new_student->next = head;
            }
            else
            {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = new_student;
                new_student->next = head;
            }
        }

    }
    void remove_student(int student_id)
    {
        if (isEmpty()) {
            cout << "No students in the system." << "\n";
            return;
        }
        else if (head->student_id == student_id && head->next == head) {
            // just one node in the list
            delete head;
            head = NULL;
        }
        else if (head->student_id == student_id) {
            // the head has the id and there are many nodes
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            head = head->next;
            curr->next = head;
            delete curr;
            cout << "Student with ID " << student_id << " removed" << "\n";
        }
        else {
            // the node is in the middle
            Node* curr = head;
            Node* prev = NULL;
            do {
                if (curr->student_id == student_id) {
                    cout << "Student with ID " << student_id << " removed" << "\n";
                    if (prev)
                        prev->next = curr->next;
                    else
                        head = curr->next;
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);

            cout << "No student found with ID " << student_id << "." << "\n";
        }
    }

    void updateStudentDetails(string studentName, int newID, int newTotal)
    {
        Node* update = head;

        if (isEmpty()) {
            cout << "No students in the system." << "\n";
            return;
        }

        do {
            if (update->name == studentName) {
                //update->grade = newGrade;
                update->student_id = newID;
                update->total = newTotal;

                //cout << "Updated " << studentName << "'s Grade to " << newGrade << "\n";
                cout << "Updated " << studentName << "'s ID to " << newID << "\n";
                cout << "Updated " << studentName << "'s Total to " << newTotal << "\n";
                assignGrade(update);
                return;
            }
            update = update->next;
        } while (update != head);

        cout << "Student not found: " << studentName << "\n";
    }

    void assignGrade(Node* student)
    {
        if (student->total >= 200) {
            cout << "Total NOT correct" << endl;
        }
        else if (student->total <= 100) {
            student->grade = "F";
        }
        else if (student->total > 100 && student->total <= 110) {
            student->grade = "D";
        }
        else if (student->total > 110 && student->total <= 120) {
            student->grade = "D+";
        }
        else if (student->total > 120 && student->total <= 130) {
            student->grade = "C";
        }
        else if (student->total > 130 && student->total <= 140) {
            student->grade = "C+";
        }
        else if (student->total > 140 && student->total <= 150) {
            student->grade = "B";
        }
        else if (student->total > 150 && student->total <= 160) {
            student->grade = "B+";
        }
        else if (student->total > 160 && student->total <= 170) {
            student->grade = "A";
        }
        else if (student->total > 170 && student->total <= 200) {
            student->grade = "A+";
        }
        else {
            cout << "Total NOT correct" << endl;
        }
    }

    void displayStudent()
    {
        if (isEmpty()) {
            cout << "No students in your list" << endl;
        }
        else {
            Node* curr = head;
            do
            {
                cout << "Student ID: " << curr->student_id << "\tStudent Name: " << curr->name << "\tStudent Total:" << curr->total << "\tStudent Grade: " << curr->grade << endl;
                curr = curr->next;
            } while (curr != head);
            cout << endl;
        }
    }
    void searchStudent(int student_id) {
        if (isEmpty()) {
            cout << "No students in your list\n";
        }
        else {
            Node* curr = head;
            while (curr->next != head) {
                if (curr->student_id == student_id) {
                    cout << "Student ID: " << curr->student_id << "\tStudent Name: " << curr->name << "\tStudent Total:" << curr->total << "\tStudent Grade: " << curr->grade << "\n";
                    return;

                }
                else {
                    curr = curr->next;
                }
            }if (curr->next == head) {
                if (curr->student_id == student_id) {
                    cout << "Student ID: " << curr->student_id << "\tStudent Name: " << curr->name << "\tStudent Total:" << curr->total << "\tStudent Grade: " << curr->grade << "\n";
                    return;

                }
                else {
                    cout << "student not found" << "\n";
                }
            }

        }
    }



    // Menu
    void displayMenu()
    {
        cout << "Menu:\n";
        cout << "1. Add Students\n";
        cout << "2. Update Student Details\n";
        cout << "3. Display Students\n";
        cout << "4. Remove Student\n";
        cout << "5. search student\n";
        cout << "6. Exit\n";
    }

    void executeMenuChoice(int choice)
    {
        string updateName;
        int newId, newTotal;
        int id, total;
        string name;

        switch (choice)
        {
        case 1:
            cout << "Adding students.\n";
            add_student(id,name,total);
             displayStudent();
            break;

        case 2:
            cout << "Enter Student Name to Update: ";
            cin >> updateName;
            cout << "Enter New Student ID: ";
            cin >> newId;
            cout << "Enter New Student Total: ";
            cin >> newTotal;
            updateStudentDetails(updateName, newId, newTotal);
            break;

        case 3:
            displayStudent();
            break;

        case 4:
            int removeId;
            cout << "Enter Student ID to Remove: ";
            cin >> removeId;
            remove_student(removeId);
            break;

        case 5:
            int searchId;
            cout << "Enter student ID to search: ";
            cin >> searchId;
            searchStudent(searchId);
            break;
            
        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            break;
        }
    }

    void runMenu()
    {
        int choice;
        do
        {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            executeMenuChoice(choice);

        } while (choice != 6);
    }
};

int main()
{
    Circular_Linked_List c;
    cout << "--------------------------- Welcome to our grading system---------------------" << endl;
    cout << "\nChoose a function" << endl;

    c.runMenu();

    return 0;
}