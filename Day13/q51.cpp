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

    int max=arr[0],min=arr[0];

    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    cout<<"Maximum element in the array is: "<<max<<endl;
    cout<<"Minimum element in the array is: "<<min;
    return 0;
}