#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int choice;

    do
    {
        cout << "\n===== Array Operations =====" << endl;
        cout << "1. Display Array" << endl;
        cout << "2. Maximum Element" << endl;
        cout << "3. Minimum Element" << endl;
        cout << "4. Sum of Elements" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                for (int i = 0; i < 5; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;

            case 2:
            {
                int max = arr[0];
                for (int i = 1; i < 5; i++)
                {
                    if (arr[i] > max)
                        max = arr[i];
                }
                cout << "Maximum = " << max << endl;
                break;
            }

            case 3:
            {
                int min = arr[0];
                for (int i = 1; i < 5; i++)
                {
                    if (arr[i] < min)
                        min = arr[i];
                }
                cout << "Minimum = " << min << endl;
                break;
            }

            case 4:
            {
                int sum = 0;
                for (int i = 0; i < 5; i++)
                {
                    sum += arr[i];
                }
                cout << "Sum = " << sum << endl;
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