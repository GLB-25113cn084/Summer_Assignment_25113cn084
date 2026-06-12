#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number to print its largest prime factors: ";
    cin >> num;
    cout << "The largest prime factor of " << num << " is: ";
    int largest_factor = 0;
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            largest_factor = i;
            num /= i;
        }
    }
    cout << largest_factor << endl;
    return 0;
}