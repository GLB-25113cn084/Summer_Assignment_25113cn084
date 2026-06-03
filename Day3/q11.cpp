#include <iostream>
using namespace std;

int main()
{
    int a, b, gcd;

    cout << "Enter two numbers to find their greatest common divisor--";
    cin >> a >> b;

    for (int i = 1; i <= a && i <= b; i++)
    {

        if (a % i == 0 && b % i == 0)

            gcd = i;

    }

    cout << "The greatest common divisor is: " << gcd << endl;

    return 0;
}