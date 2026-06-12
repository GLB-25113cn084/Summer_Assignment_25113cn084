#include <iostream>
using namespace std;

int perfect(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) sum += i;
        
    if (sum == n) return 1;
    else return 0;
}

int main()
{
    int n;
    cout << "Enter a number to check if it's a perfect number: ";
    cin >> n;

    if (perfect(n))
        cout << "The number is a perfect number." << endl;
    else
        cout << "The number is not a perfect number." << endl;

    return 0;
}