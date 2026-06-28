#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Book
{
    int bookId;
    char title[50];
    char author[50];
    int quantity;
};

void addBook()
{
    Book b;

    ofstream file("library.dat", ios::binary | ios::app);

    cout << "\nEnter Book ID: ";
    cin >> b.bookId;

    cin.ignore();

    cout << "Enter Book Title: ";
    cin.getline(b.title, 50);

    cout << "Enter Author Name: ";
    cin.getline(b.author, 50);

    cout << "Enter Quantity: ";
    cin >> b.quantity;

    file.write((char *)&b, sizeof(b));

    file.close();

    cout << "Book added successfully.\n";
}

void displayAll()
{
    Book b;

    ifstream file("library.dat", ios::binary);

    while(file.read((char *)&b, sizeof(b)))
    {
        cout << "\nBook Record\n";
        cout << "Book ID : " << b.bookId << endl;
        cout << "Title   : " << b.title << endl;
        cout << "Author  : " << b.author << endl;
        cout << "Quantity: " << b.quantity << endl;
        cout << "---------------------------" << endl;
    }

    file.close();
}

void searchBook()
{
    Book b;
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    ifstream file("library.dat", ios::binary);

    while(file.read((char *)&b, sizeof(b)))
    {
        if(b.bookId == id)
        {
            cout << "\nBook Found\n";
            cout << "Book ID : " << b.bookId << endl;
            cout << "Title   : " << b.title << endl;
            cout << "Author  : " << b.author << endl;
            cout << "Quantity: " << b.quantity << endl;

            found = true;
            break;
        }
    }

    if(!found)
        cout << "Record Not Found.\n";

    file.close();
}

void updateBook()
{
    Book b;
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Update: ";
    cin >> id;

    ifstream file("library.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&b, sizeof(b)))
    {
        if(b.bookId == id)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Title: ";
            cin.getline(b.title, 50);

            cout << "Enter New Author: ";
            cin.getline(b.author, 50);

            cout << "Enter New Quantity: ";
            cin >> b.quantity;
        }

        temp.write((char *)&b, sizeof(b));
    }

    file.close();
    temp.close();

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if(found)
        cout << "Record Updated Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

void deleteBook()
{
    Book b;
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Delete: ";
    cin >> id;

    ifstream file("library.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&b, sizeof(b)))
    {
        if(b.bookId == id)
        {
            found = true;
        }
        else
        {
            temp.write((char *)&b, sizeof(b));
        }
    }

    file.close();
    temp.close();

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if(found)
        cout << "Record Deleted Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

int main()
{
    int choice;

    cout << "========================================\n";
    cout << "      Library Management System\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayAll();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                updateBook();
                break;

            case 5:
                deleteBook();
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