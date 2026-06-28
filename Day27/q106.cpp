#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Employee
{
    int empId;
    char name[50];
    char department[30];
    float salary;
};

void addEmployee()
{
    Employee e;

    ofstream file("employee.dat", ios::binary | ios::app);

    cout << "\nEnter Employee ID: ";
    cin >> e.empId;

    cin.ignore();

    cout << "Enter Employee Name: ";
    cin.getline(e.name, 50);

    cout << "Enter Department: ";
    cin.getline(e.department, 30);

    cout << "Enter Salary: ";
    cin >> e.salary;

    file.write((char *)&e, sizeof(e));

    file.close();

    cout << "Employee added successfully.\n";
}

void displayAll()
{
    Employee e;

    ifstream file("employee.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        cout << "\nEmployee Record\n";
        cout << "Employee ID : " << e.empId << endl;
        cout << "Name        : " << e.name << endl;
        cout << "Department  : " << e.department << endl;
        cout << "Salary      : " << e.salary << endl;
        cout << "---------------------------\n";
    }

    file.close();
}

void searchEmployee()
{
    Employee e;
    int id;
    bool found = false;

    cout << "\nEnter Employee ID to search: ";
    cin >> id;

    ifstream file("employee.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        if (e.empId == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee ID : " << e.empId << endl;
            cout << "Name        : " << e.name << endl;
            cout << "Department  : " << e.department << endl;
            cout << "Salary      : " << e.salary << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

void updateEmployee()
{
    Employee e;
    int id;
    bool found = false;

    cout << "\nEnter Employee ID to update: ";
    cin >> id;

    ifstream file("employee.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        if (e.empId == id)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(e.name, 50);

            cout << "Enter New Department: ";
            cin.getline(e.department, 30);

            cout << "Enter New Salary: ";
            cin >> e.salary;
        }

        temp.write((char *)&e, sizeof(e));
    }

    file.close();
    temp.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found)
        cout << "Record updated successfully.\n";
    else
        cout << "Record not found.\n";
}

void deleteEmployee()
{
    Employee e;
    int id;
    bool found = false;

    cout << "\nEnter Employee ID to delete: ";
    cin >> id;

    ifstream file("employee.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        if (e.empId == id)
            found = true;
        else
            temp.write((char *)&e, sizeof(e));
    }

    file.close();
    temp.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}

int main()
{
    int choice;

    cout << "========================================\n";
    cout << "      Employee Management System\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- INDEX -----------\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;

        case 2:
            displayAll();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            updateEmployee();
            break;

        case 5:
            deleteEmployee();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}