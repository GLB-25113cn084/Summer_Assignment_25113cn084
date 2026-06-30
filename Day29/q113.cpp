#include <iostream>
using namespace std;

int main()
{
    int choice;
    double a, b;

    do
    {
        cout << "\n===== Calculator =====" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            cout << "Enter First Number: ";
            cin >> a;

            cout << "Enter Second Number: ";
            cin >> b;

            switch (choice)
            {
            case 1:
                cout << "Result = " << a + b << endl;
                break;

            case 2:
                cout << "Result = " << a - b << endl;
                break;

            case 3:
                cout << "Result = " << a * b << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Result = " << a / b << endl;
                else
                    cout << "Cannot divide by zero" << endl;
                break;
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting Calculator..." << endl;
        }
        else
        {
            cout << "Invalid Choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

