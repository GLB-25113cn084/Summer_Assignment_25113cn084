#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Array to store books
    string books[5];

    int count = 0;
    int choice;

    do
    {
        cout << "\n===== Mini Library =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:

                if (count < 5)
                {
                    cout << "Enter Book Name: ";
                    getline(cin, books[count]);

                    count++;
                }
                else
                {
                    cout << "Library Full" << endl;
                }

                break;

            case 2:

                cout << "\nBooks Available:" << endl;

                for (int i = 0; i < count; i++)
                {
                    cout << i + 1 << ". " << books[i] << endl;
                }

                break;

            case 3:

                cout << "Thank You" << endl;
                break;

            default:

                cout << "Invalid Choice" << endl;
        }

    } while (choice != 3);

    return 0;
}