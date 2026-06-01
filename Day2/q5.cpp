#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter the number whose digits have to be added--";
    cin >> n;

    if (n == 0) 
    {
        sum = 0;
    } 
    else 
    {
        while (n > 0) 
        {
            sum += n % 10;
            n /= 10;
        }
    }

    cout << "The sum of digits in the given number is--" << sum;

    return 0;
}