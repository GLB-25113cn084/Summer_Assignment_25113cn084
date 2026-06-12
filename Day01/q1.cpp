#include <iostream>

using namespace std;

int main()
{
    int n,sum=0;
    cout<< "Enter the last number of the series that is to be added--";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum+=i;
    }
    cout<< "The sum of the series is--"<<sum;
    return 0;

}