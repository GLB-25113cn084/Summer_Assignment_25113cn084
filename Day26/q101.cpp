#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess;

    cout << "Guess a number between 1 and 100. You have 5 chances!" << endl;

    for (int attempts = 1; attempts <= 5; attempts++) {
        cout << "Attempt " << attempts << "/5 - Enter your guess: ";
        cin >> guess;

        if (guess < secret)
            cout << "Too low! Try again." << endl;
        else if (guess > secret)
            cout << "Too high! Try again." << endl;
        else {
            cout << "Correct! You guessed it in " << attempts << " attempt(s)." << endl;
            return 0;
        }
    }

    cout << "Out of attempts! The number was " << secret << "." << endl;

    return 0;
}
