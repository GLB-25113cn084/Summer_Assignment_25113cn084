#include <iostream>

using namespace std;

int main()
{
    int n, count = 0;
    cout << "Enter the number whose digits have to be added--";
    cin >> n;

    if (n == 0) 
    {
        count = 1;
    } 
    else 
    {
        while (n > 0) 
        {
            n /= 10;
            count++;
        }
    }

    cout << "The number of digits in the given number is--" << count;

    return 0;
}