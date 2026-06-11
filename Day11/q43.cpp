#include <iostream>
using namespace std;

int check_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }

int main()
{
    int n;
    cout << "Enter the number to check if it is a prime number--";
    cin >> n;
    if (check_prime(n))
    {
        cout << "The entered number is a prime number.";
    }
    else
    {
        cout << "The entered number is not a prime number.";
    }
    return 0;
}