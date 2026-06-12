#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number to print its factors: ";
    cin >> num;
    cout << "The factors of " << num << " are: ";
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}