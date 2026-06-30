#include <iostream>
#include <string>
using namespace std;

int main()
{
    string product = "";
    int quantity = 0;
    int choice;

    do
    {
        cout << "\n===== Inventory Management =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Product" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Enter Product Name: ";
                getline(cin, product);

                cout << "Enter Quantity: ";
                cin >> quantity;
                break;

            case 2:
                cout << "\nProduct Name : " << product << endl;
                cout << "Quantity     : " << quantity << endl;
                break;

            case 3:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }

    } while (choice != 3);

    return 0;
}