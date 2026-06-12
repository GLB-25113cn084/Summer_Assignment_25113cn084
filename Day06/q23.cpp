#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num,count = 0;
    cout << "Enter a number to count the set bits: ";
    cin >> num;
    int temp = num;
    while (temp > 0)
    {
        if (temp & 1)
        {
            count++;
        }
        temp = temp >> 1;
    }
    cout << "Number of set bits = " << count << endl;
    return 0;
}