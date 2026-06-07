#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, sum = 0, remainder;
    cout << "Enter a number to check if it's a perfect number: ";
    cin >> num;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    if (sum == num)
    {
        cout << "The number is a perfect number." << endl;
    }
    else
    {
        cout << "The number is not a perfect number." << endl;
    }

    return 0;
}    