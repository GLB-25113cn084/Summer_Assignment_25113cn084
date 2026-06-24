#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int freq[256] = {0};

    for (int i = 0; i < str.length(); i++)
        freq[str[i]]++;

    bool found = false;
    for (int i = 0; i < str.length(); i++) {
        if (freq[str[i]] > 1) {
            cout << "First repeating character: " << str[i];
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No repeating character found.";

    return 0;
}