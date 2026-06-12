#include <iostream>

using namespace std;

int main()
{
    int n,reverse_num = 0;
    cout << "Enter the number--";
    cin >> n;
    while (n > 0)
    {
        reverse_num = 10 * reverse_num + n % 10;
        n /= 10;
    }
    cout << "The reverse of the given number is--" << reverse_num;
    return 0;

}