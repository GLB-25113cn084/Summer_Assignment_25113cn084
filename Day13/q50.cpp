#include <iostream>
using namespace std;

int main()
{
    int n,sum=0,average;
    cout<<"Enter the size of array: ";
    cin>>n; 
    int arr[n];

    for (int i = 0; i < n; i++)
        cin>>arr[i];

    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    average=sum/n;
    cout<<"Sum of array elements is: "<<sum<<endl;
    cout<<"Average of array elements is: "<<average;
    return 0;
}