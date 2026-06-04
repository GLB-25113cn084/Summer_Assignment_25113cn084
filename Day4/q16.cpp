#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int end_num;


    cout << "Enter ending number: ";
    cin >> end_num;

    for (int num = 1; num <= end_num; num++)
    {
        int temp = num;
        int count = 0;
        int result = 0;

        // Count digits
        while (temp > 0)
        {
            count++;
            temp /= 10;
        }

        temp = num;

        while (temp > 0)
        {
            int digit = temp % 10;
            result += round(pow(digit, count));
            temp /= 10;
        }

        if (result == num)
            cout << num << " ";
    }

    return 0;
}