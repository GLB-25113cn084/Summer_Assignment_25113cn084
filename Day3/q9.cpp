#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number to check if it is a prime number--";
    cin >> n;
    if (n <= 1)
    {
        cout << "The entered number is not a prime number.";
        return 0;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << "The entered number is not a prime number.";
            return 0;
        }
    }
    cout << "The entered number is a prime number.";
    return 0;
}