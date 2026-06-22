#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            freq[s[i] - 'a']++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            freq[s[i] - 'A']++;
    }
    cout << "Character frequencies:" << endl;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            cout << (char)('a' + i) << " : " << freq[i] << endl;
    }
    return 0;
}
