#include <iostream>
using namespace std;

int main()
{
    int num,decimal = 0, base = 1;
    cout << "Enter a binary number to convert it into decimal: ";
    cin >> num;
    int temp = num;
    while (temp > 0)
    {
        int last_digit = temp % 10;
        decimal += last_digit * base;
        temp = temp / 10;
        base = base * 2;
    }
    cout << "Decimal number = " << decimal << endl;
    return 0;   
}