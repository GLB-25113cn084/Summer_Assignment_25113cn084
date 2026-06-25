#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line, word;
    vector<string> longestWords;
    int maxLen = 0;

    cout << "Enter a sentence: ";
    getline(cin, line);

    stringstream ss(line);
    while (ss >> word) {
        if (word.length() > maxLen) {
            maxLen = word.length();
            longestWords.clear();
            longestWords.push_back(word);
        } 
        else if (word.length() == maxLen)
            longestWords.push_back(word);
    }

    cout << "Longest word(s) (" << maxLen << " characters):" << endl;
    for (string w : longestWords)
        cout << "  " << w << endl;

    return 0;
}
