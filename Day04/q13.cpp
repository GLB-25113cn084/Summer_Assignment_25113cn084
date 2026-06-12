#include <iostream>

using namespace std;

int main()
{
    int n, first_term = 0, second_term = 1, next_term;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
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
    cout << endl;
    return 0;
}