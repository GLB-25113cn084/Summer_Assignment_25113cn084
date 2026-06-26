#include <iostream>
#include <string>
using namespace std;

struct Question {
    string text;
    string options[4];
    int correct; // 1-indexed
};

int main() {
    Question quiz[] = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Rome"},
            3
        },
        {
            "How many days are there in a leap year?",
            {"365", "366", "364", "367"},
            2
        },
        {
            "Which planet is known as the Red Planet?",
            {"Venus", "Jupiter", "Earth", "Mars"},
            4
        },
        {
            "How many sides does a hexagon have?",
            {"5", "7", "6", "8"},
            3
        },
        {
            "What is the largest ocean on Earth?",
            {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
            4
        },
        {
            "Who wrote the play 'Romeo and Juliet'?",
            {"Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"},
            2
        },
        {
            "What is 12 x 12?",
            {"132", "144", "124", "148"},
            2
        },
        {
            "Which gas do plants absorb from the atmosphere?",
            {"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"},
            3
        },
        {
            "What is the smallest continent?",
            {"Antarctica", "Europe", "Australia", "South America"},
            3
        },
        {
            "How many hours are there in a day?",
            {"12", "48", "36", "24"},
            4
        }
    };

    int total = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    string name;

    cout << "===== Welcome to the General Knowledge Quiz =====" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "\nHello, " << name << "! The quiz has " << total << " questions." << endl;
    cout << "Enter the option number (1-4) for each answer.\n" << endl;

    for (int i = 0; i < total; i++) {
        cout << "Q" << (i + 1) << ": " << quiz[i].text << endl;
        for (int j = 0; j < 4; j++) {
            cout << "  " << (j + 1) << ". " << quiz[i].options[j] << endl;
        }

        int answer;
        cout << "Your answer: ";
        cin >> answer;

        if (answer < 1 || answer > 4) {
            cout << "Invalid input. Skipping question.\n" << endl;
            continue;
        }

        if (answer == quiz[i].correct) {
            cout << "Correct!\n" << endl;
            score++;
        } else {
            cout << "Wrong! Correct answer: " << quiz[i].correct << ". " << quiz[i].options[quiz[i].correct - 1] << "\n" << endl;
        }
    }

    cout << "===== Quiz Finished! =====" << endl;
    cout << "Player: " << name << endl;
    cout << "Score : " << score << " / " << total << endl;

    if (score == total)
        cout << "Result: Outstanding! Perfect score!" << endl;
    else if (score >= total * 0.8)
        cout << "Result: Excellent!" << endl;
    else if (score >= total * 0.6)
        cout << "Result: Good job!" << endl;
    else if (score >= total * 0.4)
        cout << "Result: Needs improvement." << endl;
    else
        cout << "Result: Better luck next time!" << endl;

    return 0;
}
