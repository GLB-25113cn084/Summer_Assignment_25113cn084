#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    bool seen[256] = {false};
    string result = "";

    for (char c : s) {
        if (!seen[c]) {
            seen[c] = true;
            result += c;
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "After removing duplicates: " << removeDuplicates(s) << endl;

    return 0;
}
