#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string correctPIN = "1234";
    string enteredPIN;
    double balance = 15000.00;
    int choice;
    int attempts = 0;

    cout << "======================================" << endl;
    cout << "         Welcome to IndianBank ATM    " << endl;
    cout << "======================================" << endl;

    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == correctPIN) {
            cout << "\nPIN accepted. Welcome!\n" << endl;
            break;
        } else {
            attempts++;
            if (attempts < 3)
                cout << "Incorrect PIN. " << (3 - attempts) << " attempt(s) remaining.\n" << endl;
        }
    }

    if (attempts == 3) {
        cout << "Too many incorrect attempts. Card blocked. Please contact your bank." << endl;
        return 0;
    }

    bool running = true;
    while (running) {
        cout << "--------------------------------------" << endl;
        cout << "         Main Menu                    " << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << fixed << setprecision(2);
                cout << "\nYour current balance is: Rs. " << balance << "\n" << endl;
                break;

            case 2: {
                double amount;
                cout << "Enter amount to deposit: Rs. ";
                cin >> amount;
                if (amount <= 0) {
                    cout << "Invalid amount. Please enter a positive value.\n" << endl;
                } else {
                    balance += amount;
                    cout << fixed << setprecision(2);
                    cout << "Rs. " << amount << " deposited successfully." << endl;
                    cout << "New balance: Rs. " << balance << "\n" << endl;
                }
                break;
            }

            case 3: {
                double amount;
                cout << "Enter amount to withdraw: Rs. ";
                cin >> amount;
                if (amount <= 0) {
                    cout << "Invalid amount. Please enter a positive value.\n" << endl;
                } else if (amount > balance) {
                    cout << "Insufficient balance. Transaction failed.\n" << endl;
                } else {
                    balance -= amount;
                    cout << fixed << setprecision(2);
                    cout << "Rs. " << amount << " withdrawn successfully." << endl;
                    cout << "Remaining balance: Rs. " << balance << "\n" << endl;
                }
                break;
            }

            case 4:
                cout << "\nThank you for using IndianBank ATM. Goodbye!" << endl;
                running = false;
                break;

            default:
                cout << "Invalid choice. Please select between 1 and 4.\n" << endl;
        }
    }

    return 0;
}
