#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Arrays to store employee names and salaries
    string name[5];
    double salary[5];

    int count = 0;
    int choice;

    do
    {
        cout << "\n===== Employee Management =====" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. View Employees" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:

                if (count < 5)
                {
                    cout << "Enter Employee Name: ";
                    getline(cin, name[count]);

                    cout << "Enter Salary: ";
                    cin >> salary[count];

                    count++;
                }
                else
                {
                    cout << "Record Full" << endl;
                }

                break;

            case 2:

                cout << "\nEmployee Details" << endl;

                for (int i = 0; i < count; i++)
                {
                    cout << i + 1 << ". " << name[i]
                         << " - ₹" << salary[i] << endl;
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