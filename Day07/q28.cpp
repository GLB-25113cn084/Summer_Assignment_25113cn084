#include <iostream>

using namespace std;
int reverse_num(int n, int rev = 0)
{
    if (n == 0)
        return rev;
    else
        return reverse_num(n / 10, rev * 10 + n % 10);
}
int main()
{
    int n;
    cout << "Enter the number--";
    cin >> n;
    cout << "The reverse of the given number is--" << reverse_num(n);
    return 0;
}