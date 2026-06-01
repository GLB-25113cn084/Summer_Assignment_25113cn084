#include <iostream>

using namespace std;

int main()
{
    int n,factorial=1;
    cout<< "Enter the number whose factorial is to be printed--";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        factorial*=i;
    }
    cout<< "The factorial of "<<n<<" is--"<<factorial;
    return 0;
}