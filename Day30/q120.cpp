#include <iostream>
#include <string>
using namespace std;

string customer[5];
bool booked[5] = {false, false, false, false, false};

void bookRoom()
{
    int room;

    cout << "Enter Room Number (1-5): ";
    cin >> room;

    if (room < 1 || room > 5)
    {
        cout << "Invalid Room Number!" << endl;
        return;
    }

    if (booked[room - 1])
    {
        cout << "Room Already Booked!" << endl;
    }
    else
    {
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customer[room - 1]);

        booked[room - 1] = true;

        cout << "Room Booked Successfully!" << endl;
    }
}

void viewRooms()
{
    cout << "\n===== Room Status =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Room " << i + 1 << " : ";

        if (booked[i])
            cout << "Booked by " << customer[i] << endl;
        else
            cout << "Available" << endl;
    }
}

void cancelBooking()
{
    int room;

    cout << "Enter Room Number to Cancel (1-5): ";
    cin >> room;

    if (room < 1 || room > 5)
    {
        cout << "Invalid Room Number!" << endl;
        return;
    }

    if (!booked[room - 1])
    {
        cout << "Room is Already Available!" << endl;
    }
    else
    {
        booked[room - 1] = false;
        customer[room - 1] = "";

        cout << "Booking Cancelled Successfully!" << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== Hotel Room Booking System ==========" << endl;
        cout << "1. Book Room" << endl;
        cout << "2. View Rooms" << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bookRoom();
                break;

            case 2:
                viewRooms();
                break;

            case 3:
                cancelBooking();
                break;

            case 4:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}