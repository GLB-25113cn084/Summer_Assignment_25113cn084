#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, sum = 0, remainder;
    cout << "Enter a number to check if it's a happy number: ";
    cin >> num;

    while (sum != 1)
    {
        sum = 0;
        while (num > 0)
        {
            remainder = num % 10;
            sum = sum + pow(remainder, 2);
            num = num / 10;
        }
        num = sum;
    }

    cout << "The number is a happy number." << endl;
    return 0;
}
        