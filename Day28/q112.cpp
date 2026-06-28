#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Ticket
{
    int ticketNo;
    char name[50];
    char destination[50];
    float fare;
};

void bookTicket()
{
    Ticket t;

    ofstream file("ticket.dat", ios::binary | ios::app);

    cout << "\nEnter Ticket Number: ";
    cin >> t.ticketNo;

    cin.ignore();

    cout << "Enter Passenger Name: ";
    cin.getline(t.name, 50);

    cout << "Enter Destination: ";
    cin.getline(t.destination, 50);

    cout << "Enter Fare: ";
    cin >> t.fare;

    file.write((char *)&t, sizeof(t));

    file.close();

    cout << "Ticket Booked Successfully.\n";
}

void displayAll()
{
    Ticket t;

    ifstream file("ticket.dat", ios::binary);

    while(file.read((char *)&t, sizeof(t)))
    {
        cout << "\nTicket Record\n";
        cout << "Ticket Number : " << t.ticketNo << endl;
        cout << "Passenger Name: " << t.name << endl;
        cout << "Destination   : " << t.destination << endl;
        cout << "Fare          : " << t.fare << endl;
        cout << "-----------------------------" << endl;
    }

    file.close();
}

void searchTicket()
{
    Ticket t;
    int no;
    bool found = false;

    cout << "\nEnter Ticket Number to Search: ";
    cin >> no;

    ifstream file("ticket.dat", ios::binary);

    while(file.read((char *)&t, sizeof(t)))
    {
        if(t.ticketNo == no)
        {
            cout << "\nTicket Found\n";
            cout << "Ticket Number : " << t.ticketNo << endl;
            cout << "Passenger Name: " << t.name << endl;
            cout << "Destination   : " << t.destination << endl;
            cout << "Fare          : " << t.fare << endl;

            found = true;
            break;
        }
    }

    if(!found)
        cout << "Record Not Found.\n";

    file.close();
}

void updateTicket()
{
    Ticket t;
    int no;
    bool found = false;

    cout << "\nEnter Ticket Number to Update: ";
    cin >> no;

    ifstream file("ticket.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&t, sizeof(t)))
    {
        if(t.ticketNo == no)
        {
            found = true;

            cin.ignore();

            cout << "Enter New Passenger Name: ";
            cin.getline(t.name, 50);

            cout << "Enter New Destination: ";
            cin.getline(t.destination, 50);

            cout << "Enter New Fare: ";
            cin >> t.fare;
        }

        temp.write((char *)&t, sizeof(t));
    }

    file.close();
    temp.close();

    remove("ticket.dat");
    rename("temp.dat", "ticket.dat");

    if(found)
        cout << "Record Updated Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

void deleteTicket()
{
    Ticket t;
    int no;
    bool found = false;

    cout << "\nEnter Ticket Number to Delete: ";
    cin >> no;

    ifstream file("ticket.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while(file.read((char *)&t, sizeof(t)))
    {
        if(t.ticketNo == no)
        {
            found = true;
        }
        else
        {
            temp.write((char *)&t, sizeof(t));
        }
    }

    file.close();
    temp.close();

    remove("ticket.dat");
    rename("temp.dat", "ticket.dat");

    if(found)
        cout << "Record Deleted Successfully.\n";
    else
        cout << "Record Not Found.\n";
}

int main()
{
    int choice;

    cout << "========================================\n";
    cout << "        Ticket Booking System\n";
    cout << "========================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Book Ticket\n";
        cout << "2. Display All Tickets\n";
        cout << "3. Search Ticket\n";
        cout << "4. Update Ticket\n";
        cout << "5. Delete Ticket\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                displayAll();
                break;

            case 3:
                searchTicket();
                break;

            case 4:
                updateTicket();
                break;

            case 5:
                deleteTicket();
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