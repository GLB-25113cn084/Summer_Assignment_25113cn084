#include <iostream>
using namespace std;

int factorial(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
        factorial *= i;

    return factorial;
}

int main()
{
    int n;
    cout << "enter the number to find its factorial:- ";
    cin >> n;

    cout << "the factorial of " << n << " is: " << factorial(n);
    return 0;
}