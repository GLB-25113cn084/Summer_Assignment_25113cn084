#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, citizenship;
    int age;
    char mentallySound;

    cout << "====== Voting Eligibility Checker ======" << endl;

    cout << "What's your name? ";
    getline(cin, name);

    cout << "How old are you? ";
    cin >> age;

    cout << "Are you an Indian citizen? (yes/no): ";
    cin >> citizenship;

    cout << "Are you of sound mind? (y/n): ";
    cin >> mentallySound;

    cout << "Checking your voting eligibility...\n" << endl;

    if (age < 18) {
        cout << "Sorry, you are not eligible to vote because you are under 18 years of age." << endl;
    }
    else if (citizenship != "yes") {
        cout << "Sorry, only Indian citizens are eligible to vote." << endl;
    }
    else if (mentallySound == 'n' || mentallySound == 'N') {
        cout << "Sorry, a voter must be of sound mind to be eligible." << endl;
    }
    else {
        cout << "Congratulations! You are eligible to vote." << endl;
        cout << "You can register yourself on the Electoral Roll." << endl;
    }

    return 0;
}