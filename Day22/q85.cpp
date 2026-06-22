#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            t += s[i];
    }

    int n = t.length();
    bool isPalindrome = true;

    for (int i = 0; i < n / 2; i++) {
        if (t[i] != t[n - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;

    return 0;
}
