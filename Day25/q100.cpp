#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    string words[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter word " << i + 1 << ": ";
        cin >> words[i];
    }

    sort(words, words + n, [](const string &a, const string &b) {
        return a.length() < b.length();
    });

    cout << "\nWords sorted by length:\n";
    for (int i = 0; i < n; i++)
        cout << words[i] << "\n";

    return 0;
}
