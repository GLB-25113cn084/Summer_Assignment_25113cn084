#include <iostream>

using namespace std;

int main()
{
    int n,reverse_num = 0, original_num;
    cout << "Enter the number to check if it is a palindrome number--";
    cin >> n;
    original_num = n;
    while (n > 0)
    {
        reverse_num = 10 * reverse_num + n % 10;
        n /= 10;
    }
    if (original_num == reverse_num)
    {
        cout << "The given number is a palindrome number.";
    }
    else
    {
        cout << "The given number is not a palindrome number.";
    }
    return 0;
}