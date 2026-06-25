#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of names: ";
    cin >> n;
    cin.ignore();

    string names[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    sort(names, names + n);

    cout << "\nSorted names:\n";
    for (int i = 0; i < n; i++)
        cout << names[i] << "\n";

    return 0;
}
