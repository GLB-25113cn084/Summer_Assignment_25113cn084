#include <iostream>
#include <cmath>
using namespace std;

int armstrong(int num)
{
    int original_num = num, result = 0, count = 0, remainder;

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
    return result == num;
}

int main()
{
    int num;
    cout<<"Enter the number to check if it's an armstrong number:- ";
    cin>> num;
    if (armstrong(num))
        cout << "The given number is an armstrong number." << endl;
    else
        cout << "The given number is not an armstrong number." << endl;
}