//find string length without strlen()
#include <iostream>
using namespace std;

int stringLength(const char* str) {
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    cout << "Length: " << stringLength(str) << endl;
    return 0;
}
