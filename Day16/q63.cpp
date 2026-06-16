#include <iostream>
using namespace std;
int main()
{
    int n,target;
    
    cout<<"enter the number of elements and the required target";
    cin>> n >> target;
    int arr[n];
    cout<<"enter the elements of the array: "<<endl;
    for( int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                cout<<"the required indices are-- "<<i<<" and "<<j<< " and the required elements are-- "<<arr[i]<<" and "<<arr[j]<<endl;
            }
        }
    }
    cout<<"no such indices found";
    return 0;
}
