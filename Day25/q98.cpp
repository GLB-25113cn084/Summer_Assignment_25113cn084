#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    // freq[i][c] = min count of character c across all strings so far
    int freq[26];
    for (int c = 0; c < 26; c++) freq[c] = 2147483647;

    for (int i = 0; i < n; i++) {
        string s;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, s);

        int count[26] = {0};
        for (char ch : s)
            if (ch >= 'a' && ch <= 'z') count[ch - 'a']++;

        for (int c = 0; c < 26; c++)
            freq[c] = min(freq[c], count[c]);
    }

    cout << "Common characters: ";
    bool found = false;
    for (int c = 0; c < 26; c++) {
        for (int k = 0; k < freq[c]; k++) {
            cout << (char)('a' + c) << " ";
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << endl;

    return 0;
}
