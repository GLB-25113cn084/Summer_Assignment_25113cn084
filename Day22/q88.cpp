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
    cout<<"The string after removing the spaces is: "<<t;
}