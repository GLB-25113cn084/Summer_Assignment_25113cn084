#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number to covert it into binary: ";
    cin >> num;

    cout << "The binary representation of " << num << " is: ";

    string binary = "";
    while (num > 0)
    {
        binary = char((num % 2) + '0') + binary;
        num = num / 2;
    }

    cout << "Binary number = " << binary << endl;

    return 0;

    
}