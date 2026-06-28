#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    float marks[5];
    float average;
    char grade;
};

float calcAverage(float marks[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += marks[i];
    return sum / n;
}

char calcGrade(float avg)
{
    if (avg >= 90)
        return 'A';
    else if (avg >= 80)
        return 'B';
    else if (avg >= 70)
        return 'C';
    else if (avg >= 60)
        return 'D';
    else
        return 'F';
}

void addStudent()
{
    Student s;

    ofstream file("students.dat", ios::binary | ios::app);

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(s.name, 50);

    cout << "Enter marks for 5 subjects:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> s.marks[i];
    }

    s.average = calcAverage(s.marks, 5);
    s.grade = calcGrade(s.average);

    file.write((char *)&s, sizeof(s));

    file.close();

    cout << "Student record added successfully.\n";
}

void displayAll()
{
    Student s;

    ifstream file("students.dat", ios::binary);

    if (!file)
    {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\n";
    while (file.read((char *)&s, sizeof(s)))
    {
        cout << "\nStudent Record\n";
        cout << "Roll Number : " << s.rollNo << endl;
        cout << "Name        : " << s.name << endl;

        cout << "Marks : ";
        for (int i = 0; i < 5; i++)
        {
            cout << s.marks[i] << " ";
        }

        cout << endl;
        cout << "Average     : " << s.average << endl;
        cout << "Grade       : " << s.grade << endl;
        cout << "---------------------------" << endl;
    }


file.close();
}

void searchStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
        {
            cout << "\nStudent Found\n";
            cout << "Roll No : " << s.rollNo << endl;
            cout << "Name    : " << s.name << endl;

            for (int i = 0; i < 5; i++)
                cout << "Subject " << i + 1 << " : " << s.marks[i] << endl;

            cout << "Average : " << fixed << setprecision(2) << s.average << endl;
            cout << "Grade   : " << s.grade << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

void updateStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(s.name, 50);

            cout << "Enter new marks for 5 subjects:\n";
            for (int i = 0; i < 5; i++)
            {
                cout << "Subject " << i + 1 << ": ";
                cin >> s.marks[i];
            }

            s.average = calcAverage(s.marks, 5);
            s.grade = calcGrade(s.average);

            // Move BOTH pointers back to the beginning of this record
            file.seekg(-sizeof(s), ios::cur);
            file.seekp(file.tellg());

            file.write((char *)&s, sizeof(s));

            cout << "Record updated successfully.\n";
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

void deleteStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
            found = true;
        else
            temp.write((char *)&s, sizeof(s));
    }
    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}

int main()
{
    int choice;
    cout << "========================================\n";
    cout << "    Student Record Management System    \n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- INDEX -----------\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayAll();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 6);
    return 0;
}