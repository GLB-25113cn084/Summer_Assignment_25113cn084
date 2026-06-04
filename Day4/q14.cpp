#include <iostream>

using namespace std;

int main()
{
    int n, first_term = 0, second_term = 1, next_term;
    cout<<"enter the position of the term in fibonacci series: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
            next_term = i;
        else
        {
            next_term = first_term + second_term;
            first_term = second_term;
            second_term = next_term;
        }
    }
    cout << "The " << n << "th term in the Fibonacci series is: " << next_term << endl;
    return 0;
}