#include <iostream>
using namespace std;

int fibonacci(int n)
{
    int first_term = 0, second_term = 1, next_term;
    cout << "Fibonacci Series upto " << n << " terms is: ";
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
        cout << next_term << " ";
    }
}

int main()
{
    int n;
    cout<<"Enter the number of terms of the fibonacci series:-";
    cin>>n;
    fibonacci(n);
    return 0;
}