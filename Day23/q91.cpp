#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;
    for (int i = 0; i < str1.length(); i++)
        str1[i] = tolower(str1[i]);

    for (int i = 0; i < str2.length(); i++)
        str2[i] = tolower(str2[i]);

    if (str1.length() != str2.length()) {
        cout << "Not anagrams";
        return 0;
    }

    int freq[256] = {0};

    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i]]++;
        freq[str2[i]]--;
    }

    bool anagram = true;

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            anagram = false;
            break;
        }
    }

    if (anagram)
        cout << "The strings are anagrams.";
    else
        cout << "The strings are not anagrams.";

    return 0;
}