#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

float calculateTotal(float marks[])
{
    float sum = 0;
    for(int i = 0; i < 5; i++)
        sum += marks[i];
    return sum;
}

float calculatePercentage(float total)
{
    return total / 5;
}

char calculateGrade(float percentage)
{
    if(percentage >= 90)
        return 'A';
    else if(percentage >= 80)
        return 'B';
    else if(percentage >= 70)
        return 'C';
    else if(percentage >= 60)
        return 'D';
    else
        return 'F';
}

void addStudent()
{
    Student s;

    ofstream file("marksheet.dat", ios::binary | ios::app);

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cin.ignore();

    cout << "Enter Student Name: ";
    cin.getline(s.name, 50);

    cout << "Enter Marks of 5 Subjects(out of 100):\n";

    for(int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> s.marks[i];
    }

    s.total = calculateTotal(s.marks);
    s.percentage = calculatePercentage(s.total);
    s.grade = calculateGrade(s.percentage);

    file.write((char *)&s, sizeof(s));

    file.close();

    cout << "Marksheet Generated Successfully.\n";
}

void displayAll()
{
    Student s;

    ifstream file("marksheet.dat", ios::binary);

    while(file.read((char *)&s, sizeof(s)))
    {
        cout << "\nStudent Record\n";
        cout << "Roll Number : " << s.rollNo << endl;
        cout << "Name        : " << s.name << endl;

        cout << "Marks : ";
        for(int i = 0; i < 5; i++)
        {
            cout << s.marks[i] << " ";
        }

        cout << endl;
        cout << "Total      : " << s.total << endl;
        cout << "Percentage : " << s.percentage << "%" << endl;
        cout << "Grade      : " << s.grade << endl;
        cout << "-----------------------------" << endl;
    }

    file.close();
}

void searchStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    ifstream file("marksheet.dat", ios::binary);

    while(file.read((char *)&s, sizeof(s)))
    {
        if(s.rollNo == roll)
        {
            cout << "\nStudent Found\n";
            cout << "Roll Number : " << s.rollNo << endl;
            cout << "Name        : " << s.name << endl;

            cout << "Marks : ";
            for(int i = 0; i < 5; i++)
            {
                cout << s.marks[i] << " ";
            }

            cout << endl;
            cout << "Total      : " << s.total << endl;
            cout << "Percentage : " << s.percentage << "%" << endl;
            cout << "Grade      : " << s.grade << endl;

            found = true;
            break;
        }
    }

    if(!found)
        cout << "Record Not Found.\n";

    file.close();
}

void updateStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    ifstream file("marksheet.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&s, sizeof(s)))
    {
        if(s.rollNo == roll)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(s.name, 50);

            cout << "Enter New Marks(out of 100):\n";

            for(int i = 0; i < 5; i++)
            {
                cout << "Subject " << i + 1 << ": ";
                cin >> s.marks[i];
            }

            s.total = calculateTotal(s.marks);
            s.percentage = calculatePercentage(s.total);
            s.grade = calculateGrade(s.percentage);
        }

        temp.write((char *)&s, sizeof(s));
    }

    file.close();
    temp.close();

    remove("marksheet.dat");
    rename("temp.dat", "marksheet.dat");

    if(found)
        cout << "Record Updated Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

void deleteStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    ifstream file("marksheet.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&s, sizeof(s)))
    {
        if(s.rollNo == roll)
        {
            found = true;
        }
        else
        {
            temp.write((char *)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("marksheet.dat");
    rename("temp.dat", "marksheet.dat");

    if(found)
        cout << "Record Deleted Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

int main()
{
    int choice;

    cout << "========================================\n";
    cout << "      Marksheet Generation System\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- INDEX -----------\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Marksheets\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
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
                cout << "Invalid Choice!\n";
        }

    }while(choice != 6);

    return 0;
}