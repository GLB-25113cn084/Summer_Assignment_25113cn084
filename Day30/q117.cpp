#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name[5];
    int marks[5];

    int i = 0;
    int choice;

    do
    {
        cout << "\n===== Student Record System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:

                if (i < 5)
                {
                    cout << "Enter Student Name: ";
                    getline(cin, name[i]);

                    cout << "Enter Marks: ";
                    cin >> marks[i];

                    i++;
                }
                else
                {
                    cout << "Record Full" << endl;
                }

                break;

            case 2:

                cout << "\nStudent Records" << endl;

                for (int j = 0; j < i; j++)
                {
                    cout << j + 1 << ". " << name[j]
                         << " - " << marks[j] << endl;
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