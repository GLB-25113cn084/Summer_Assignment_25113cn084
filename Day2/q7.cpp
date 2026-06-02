#include <iostream>

using namespace std;

int main()
{
    int n, product = 1;
    cout << "Enter the number--";
    cin >> n;
    if (n == 0) 
    {
        product = 0;
    } 
    else 
    {
        while (n > 0) 
        {
            product *= n % 10;
            n /= 10;
        }
    }
    cout << "The product of digits in the given number is--" << product;
    return 0;
}