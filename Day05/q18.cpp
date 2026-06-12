
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number to check if it's a strong number: ";
    cin >> num;
    int original_num = num;
    int sum = 0, remainder;
    while (num > 0)
    {
        remainder = num % 10;
        int factorial = 1;
        for (int i = 1; i <= remainder; i++)
        {
            factorial = factorial * i;
        }
        sum = sum + factorial;
        num = num / 10;
    }
    if (sum == original_num)
    {
        cout << "The number is a strong number." << endl;
    }
    else
    {
        cout << "The number is not a strong number." << endl;
    }
    return 0;
}
