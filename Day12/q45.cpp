#include <iostream>
using namespace std;

int palindrome(int num)
{
    int reverse_num = 0, original_num = num;
    while (num > 0)
    {
        reverse_num = 10 * reverse_num + num % 10;
        num /= 10;
    }
    return original_num == reverse_num;
}

int main()
{
    int num;
    cout << "Enter the number to check if it is a palindrome number: ";
    cin >> num;
    if (palindrome(num))
    {
        cout << "The given number is a palindrome number." << endl;
    }
    else
    {
        cout << "The given number is not a palindrome number." << endl;
    }
}
