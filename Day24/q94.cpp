#include <iostream>
#include <string>
using namespace std;

string compress(string s) {
    string result = "";
    int i = 0;

    while (i < s.length()) {
        char current = s[i];
        int count = 0;

        while (i < s.length() && s[i] == current) {
            count++;
            i++;
        }

        result += current;
        if (count > 1)
            result += to_string(count);
    }

    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string compressed = compress(s);

    if (compressed.length() < s.length())
        cout << "Compressed string: " << compressed << endl;
    else
        cout << "Compression not beneficial. Original: " << s << endl;

    return 0;
}
