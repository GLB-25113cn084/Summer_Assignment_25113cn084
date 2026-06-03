#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the last number of the range to check for prime numbers--";
    cin >> n;
    cout << "Prime numbers between 1 and " << n << " are:" << endl;
    for (int i = 2; i <= n; i++)
    {
        int is_prime = 1; 
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                is_prime = 0; 
                break;
            }
        }
        if (is_prime)
        {
            cout << i << endl;
        }
    }
    return 0;
}