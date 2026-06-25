#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    string doubled = s1 + s1;
    return doubled.find(s2) != string::npos;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (isRotation(s1, s2))
        cout << "\"" << s2 << "\" is a rotation of \"" << s1 << "\"" << endl;
    else
        cout << "\"" << s2 << "\" is NOT a rotation of \"" << s1 << "\"" << endl;

    return 0;
}
