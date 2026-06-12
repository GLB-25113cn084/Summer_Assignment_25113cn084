#include <iostream>

using namespace std;

int main()
{
    int a,b,lcm;
    cout << "Enter two numbers to find their lowest common multiple--";
    cin >> a >> b;

    //check which number is greater
    int greater = (a > b) ? a : b;

    for (int i = greater;; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            lcm = i;
            break;
        }
    }
    cout << "The lowest common multiple is: " << lcm << endl;

    return 0;
}
