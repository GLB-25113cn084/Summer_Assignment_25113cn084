#include <iostream>

using namespace std;

int main()
{
    int n,product=1;
    cout<< "Enter the number whose multiplication table is to be printed--";
    cin>>n;
    for(int i=1;i<11;i++)
    {
        product*=i;
    }
    cout<< "The multiplication table of "<<n<<" is--"<<endl;
    for(int i=1;i<11;i++)
    {
        cout<<n<<" x "<<i<<" = "<<n*i<<endl;
    }
    return 0;

}