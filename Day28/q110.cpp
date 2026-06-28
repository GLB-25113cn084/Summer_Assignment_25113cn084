#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Account
{
    int accountNo;
    char name[50];
    char accountType[20];
    float balance;
};

void addAccount()
{
    Account a;

    ofstream file("bank.dat", ios::binary | ios::app);

    cout << "\nEnter Account Number: ";
    cin >> a.accountNo;

    cin.ignore();

    cout << "Enter Account Holder Name: ";
    cin.getline(a.name, 50);

    cout << "Enter Account Type (Saving/Current): ";
    cin.getline(a.accountType, 20);

    cout << "Enter Initial Balance: ";
    cin >> a.balance;

    file.write((char *)&a, sizeof(a));

    file.close();

    cout << "Account Created Successfully.\n";
}

void displayAll()
{
    Account a;

    ifstream file("bank.dat", ios::binary);

    while(file.read((char *)&a, sizeof(a)))
    {
        cout << "\nAccount Record\n";
        cout << "Account Number : " << a.accountNo << endl;
        cout << "Name           : " << a.name << endl;
        cout << "Account Type   : " << a.accountType << endl;
        cout << "Balance        : " << a.balance << endl;
        cout << "-----------------------------" << endl;
    }

    file.close();
}

void searchAccount()
{
    Account a;
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number to Search: ";
    cin >> accNo;

    ifstream file("bank.dat", ios::binary);

    while(file.read((char *)&a, sizeof(a)))
    {
        if(a.accountNo == accNo)
        {
            cout << "\nAccount Found\n";
            cout << "Account Number : " << a.accountNo << endl;
            cout << "Name           : " << a.name << endl;
            cout << "Account Type   : " << a.accountType << endl;
            cout << "Balance        : " << a.balance << endl;

            found = true;
            break;
        }
    }

    if(!found)
        cout << "Record Not Found.\n";

    file.close();
}

void updateAccount()
{
    Account a;
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number to Update: ";
    cin >> accNo;

    ifstream file("bank.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&a, sizeof(a)))
    {
        if(a.accountNo == accNo)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Name: ";
            cin.getline(a.name, 50);

            cout << "Enter New Account Type: ";
            cin.getline(a.accountType, 20);

            cout << "Enter New Balance: ";
            cin >> a.balance;
        }

        temp.write((char *)&a, sizeof(a));
    }

    file.close();
    temp.close();

    remove("bank.dat");
    rename("temp.dat", "bank.dat");

    if(found)
        cout << "Record Updated Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

void deleteAccount()
{
    Account a;
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number to Delete: ";
    cin >> accNo;

    ifstream file("bank.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&a, sizeof(a)))
    {
        if(a.accountNo == accNo)
        {
            found = true;
        }
        else
        {
            temp.write((char *)&a, sizeof(a));
        }
    }

    file.close();
    temp.close();

    remove("bank.dat");
    rename("temp.dat", "bank.dat");

    if(found)
        cout << "Record Deleted Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

int main()
{
    int choice;

    cout << "========================================\n";
    cout << "      Bank Account Management System\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Update Account\n";
        cout << "5. Delete Account\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addAccount();
                break;

            case 2:
                displayAll();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                updateAccount();
                break;

            case 5:
                deleteAccount();
                break;

            case 6:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}