#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    int choice;

    cout << "Enter a String: ";
    getline(cin, str);

    do
    {
        cout << "\n===== String Operations =====" << endl;
        cout << "1. Length" << endl;
        cout << "2. Uppercase" << endl;
        cout << "3. Lowercase" << endl;
        cout << "4. Reverse" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Length = " << str.length() << endl;
                break;

            case 2:
            {
                string upper = str;
                for (int i = 0; i < upper.length(); i++)
                    upper[i] = toupper(upper[i]);

                cout << upper << endl;
                break;
            }

            case 3:
            {
                string lower = str;
                for (int i = 0; i < lower.length(); i++)
                    lower[i] = tolower(lower[i]);

                cout << lower << endl;
                break;
            }

            case 4:
            {
                for (int i = str.length() - 1; i >= 0; i--)
                    cout << str[i];

                cout << endl;
                break;
            }

            case 5:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice! Please enter a number between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}