#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    /*for (int i = 0; str[i] != '\0'; i++) (using built-in function)
        str[i] = toupper(str[i]);*/

    cout << "Uppercase: " << str << endl;
    return 0;
}
