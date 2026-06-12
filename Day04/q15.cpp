#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, original_num, result = 0, count = 0, remainder;

    cout << "Enter the number : ";
    cin >> num;

    original_num = num;

    while (original_num > 0)
    {
        original_num = original_num / 10;
        count++;
    }

    original_num = num;

    while (original_num > 0)
    {
        remainder = original_num % 10;
        result += round(pow(remainder, count));
        original_num = original_num / 10;
    }

    if (result == num)
        cout << "The number is an armstrong number." << endl;
    else
        cout << "The number is not an armstrong number." << endl;
    return 0;
}