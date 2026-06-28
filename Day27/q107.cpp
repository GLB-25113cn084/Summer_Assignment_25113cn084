#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Employee
{
    int empId;
    char name[50];
    float basicSalary;
    float deduction;
    float netSalary;
};

float calculateNetSalary(float basicSalary, float deduction)
{
    return basicSalary - deduction;
}

void addEmployee()
{
    Employee e;

    ofstream file("salary.dat", ios::binary | ios::app);

    cout << "\nEnter Employee ID: ";
    cin >> e.empId;

    cin.ignore();

    cout << "Enter Employee Name: ";
    cin.getline(e.name, 50);

    cout << "Enter Basic Salary: ";
    cin >> e.basicSalary;

    cout << "Enter Deduction: ";
    cin >> e.deduction;

    e.netSalary = calculateNetSalary(e.basicSalary, e.deduction);

    file.write((char *)&e, sizeof(e));

    file.close();

    cout << "Employee salary record added successfully.\n";
}

void displayAll()
{
    Employee e;

    ifstream file("salary.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        cout << "\nEmployee Record\n";
        cout << "Employee ID  : " << e.empId << endl;
        cout << "Name         : " << e.name << endl;
        cout << "Basic Salary : " << e.basicSalary << endl;
        cout << "Deduction    : " << e.deduction << endl;
        cout << "Net Salary   : " << e.netSalary << endl;
        cout << "-----------------------------" << endl;
    }

    file.close();
}

void searchEmployee()
{
    Employee e;
    int id;
    bool found = false;

    cout << "\nEnter Employee ID to Search: ";
    cin >> id;

    ifstream file("salary.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        if (e.empId == id)
        {
            cout << "\nEmployee Found\n";
            cout << "Employee ID  : " << e.empId << endl;
            cout << "Name         : " << e.name << endl;
            cout << "Basic Salary : " << e.basicSalary << endl;
            cout << "Deduction    : " << e.deduction << endl;
            cout << "Net Salary   : " << e.netSalary << endl;

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

    cout << "\nEnter Employee ID to Update: ";
    cin >> id;

    ifstream file("salary.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char *)&e, sizeof(e)))
    {
        if (e.empId == id)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(e.name, 50);

            cout << "Enter New Basic Salary: ";
            cin >> e.basicSalary;

            cout << "Enter New Deduction: ";
            cin >> e.deduction;

            e.netSalary = calculateNetSalary(e.basicSalary, e.deduction);
        }

        temp.write((char *)&e, sizeof(e));
    }

    file.close();
    temp.close();

    remove("salary.dat");
    rename("temp.dat", "salary.dat");

    if (found)
        cout << "Record Updated Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

void deleteEmployee()
{
    Employee e;
    int id;
    bool found = false;

    cout << "\nEnter Employee ID to Delete: ";
    cin >> id;

    ifstream file("salary.dat", ios::binary);
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

    remove("salary.dat");
    rename("temp.dat", "salary.dat");

    if (found)
        cout << "Record Deleted Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

int main()
{
    int choice;

    cout << "========================================\n";
    cout << "        Salary Management System\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- Index -----------\n";
        cout << "1. Add Employee Salary\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
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
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 6);
    return 0;
}