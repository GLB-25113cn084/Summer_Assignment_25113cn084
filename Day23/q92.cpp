#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int freq[256] = {0};

    for (int i = 0; i < str.length(); i++)
        freq[str[i]]++;

    int maxFreq = 0;
    for (int i = 0; i < str.length(); i++)
        if (freq[str[i]] > maxFreq)
            maxFreq = freq[str[i]];

    cout << "Maximum occurring character(s) (frequency: " << maxFreq << "): ";
    bool printed[256] = {false};
    for (int i = 0; i < str.length(); i++) {
        if (freq[str[i]] == maxFreq && !printed[(unsigned char)str[i]]) {
            cout << str[i] << " ";
            printed[(unsigned char)str[i]] = true;
        }
    }

    return 0;
}